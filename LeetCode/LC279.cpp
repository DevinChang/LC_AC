//
// Created by devinchang on 2019/12/31.
//
#include "util.h"


int numSquares(int n){
    if(n < 1)
        return 0;
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    for(int i = 1; i <= n; i++){
        dp[i] = i;
        for(int j = 1; i - j * j >= 0; j++){
            dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
    }
    return dp[n];
}


int main(){
    string line;
    while(getline(cin, line)){
        int n = stringToInteger(line);
        int ret = numSquares(n);
        cout << to_string(ret) << endl;
    }

    return 0;
}

