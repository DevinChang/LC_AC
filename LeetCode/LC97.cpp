//
// Created by devinchang on 2019/12/10.
//

#include <bits/stdc++.h>
using namespace std;

bool dfs(string s1, int i, string s2, int j, string s3, int k, vector<vector<bool>> &invalid){
    if(invalid[i][j])
        return false;
    if(i + j == s3.size())
        return true;
    bool ret = i < s1.size() && s1[i] == s3[k] && dfs(s1, i+1, s2, j, s3, k+1, invalid) ||
            j < s2.size() && s2[j] == s3[k] && dfs(s1, i, s2, j+1, s3, k+1, invalid);
    if(!ret)
        invalid[i][j] = true;
    return ret;
}

bool isInterval_1223(string s1, string s2, string s3){
    int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
    if(len1 + len2 != len3)
        return false;
    vector<vector<bool>> invalid(len1, vector<bool>(len2, false));
    return dfs(s1, 0, s2, 0, s3, 0, invalid);
}

bool isInterleave(string s1, string s2, string s3){
    int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
    if(len1 + len2 != len3)
        return false;
    vector<vector<int>> dp(len1 + 1, vector<int>(len2+1, -1));
    dp[0][0] = 1;
    for(int i = 1; i <= len1; i++){
        dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
    }
    for(int j = 1; j <= len2; j++){
        dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
    }
    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
        }
    }
    return dp[len1][len2] == 1;
}

bool isInterleave_error(string s1, string s2, string s3){
    int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
    if(len1 + len2 != len3)
        return false;
    int idx1 = 0, idx2 = 0;
    unordered_map<int, bool> hash;
    for(int i = 0; i < len3; i++){
        hash[i] = false;
    }
    for(int idx3 = 0; idx3 < len3; idx3++){
        if(s3[idx3] == s2[idx2]){
            idx2++;
            hash[idx3] = true;
        }
    }
    if(idx2 != len2)
        return false;
    for(int idx3 = 0; idx3 < len3; idx3++){
        if(s3[idx3] == s1[idx1] && !hash[idx3]){
            idx1++;
        }
    }
    return idx1 == len1;
}

int main(){
    string s1 = "aabcc", s2 = "dbbca";
    string s3 = "aadbbcbcac";
    string s4 = "aadbbbaccc";
    string s5 = "aabc", s6 = "abad";
    string s7 = "aabadabc";
    string s8 = "aabcabad";
    bool ret = isInterleave(s5, s6, s8);
    cout << ret << endl;
    return 0;
}

