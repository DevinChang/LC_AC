//
// Created by devinchang on 2019/12/17.
//

#include "util.h"


int uniquePaths(int m, int n){
    if(m < 1 && n < 1)
        return 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for(int i = 1; i < m; i++)
        dp[i][0] = 1;
    for(int i = 1; i < n; i++)
        dp[0][i] = 1;
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}


int main(){
    string line;
    while(getline(cin, line)){
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);

        int ret = uniquePaths(m, n);

        string out = to_string(ret);

        cout << out << endl;
    }

    return 0;
}

