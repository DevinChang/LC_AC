//
// Created by devinchang on 2019/12/23.
//

#include "util.h"


int numDistinct(string s, string t){
    int n = s.size(), m = t.size();
    if(n < m)
        return 0;
    vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));
    for(int i = 0; i <= n; i++)
        dp[0][i] = 1;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(t[i-1] != s[j-1])
                dp[i][j] = dp[i][j-1];
            else
                dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
        }
    }
    return dp[m][n];
}



int main(){
    string line;
    while(getline(cin, line)){
        string s = stringToString(line);
        getline(cin, line);
        string t = stringToString(line);

        int ret = numDistinct(s, t);
        cout << ret << endl;
    }
    return 0;
}

