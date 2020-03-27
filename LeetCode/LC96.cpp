//
// Created by devinchang on 2019/12/20.
//

#include "util.h"



int numTrees(int n){
    if(n < 1)
        return 0;
    vector<int> dp(n+1, 0);
    dp[0] = 1, dp[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i] += dp[j-1] * dp[i-j];
        }
    }
    return dp[n];
}


int main(){
    int ret = numTrees(4);
    cout << ret << endl;
    return 0;
}

