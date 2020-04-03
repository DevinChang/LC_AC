#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


const int null = -2e9;

typedef pair<int, int> PII;

int mergeSeg(vector<PII> &segs){
    sort(segs.begin(), segs.end());
    int st = null, ed = null;
    int res = segs.size();
    for (auto seg : segs){
        if(seg.)
    }
}

int minDistance(string word1, string word2) {
    if(word1.size() < 1 && word2.size() < 1)
        return 0;
    int len1 = word1.size(), len2 = word2.size();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    for(int i = 0; i < len2 + 1; ++i)
        dp[0][i] = i;
    for(int i = 0; i < len1 + 1; ++i)
        dp[i][0] = i;
    for(int i = 1; i < len1 + 1; ++i){
        for(int j = 1; j < len2 + 1; ++j){
            if(word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
        }
    }
    return dp[len1][len2];
}



int main(){
    vector<string> words{"surprise", "happy", "ctrip", "travel", "wellcome", "student", "system", 
                        "program", "editor"};

    string str;
    bool flag = false;
    while(cin >> str){
        for(auto w : words){
            int res = minDistance(str, w);
            if(res <= 2){ 
                flag = true;
                cout << w << endl;
                break;
            }
        }
        if(!flag){
            cout << "null" << endl;
        }
        flag = false;
    }


    return 0;
}