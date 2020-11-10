//
// Created by devinchang on 2020/1/3.
//
#include "util.h"


int coinChange(vector<int>& coins, int amount){
    int len = coins.size();
    if(len < 1)
        return -1;
    vector<int> dp(amount+1, amount);
    dp[0] = 0;
    for(int i = 1; i <= amount; i++){
        for(auto c : coins){
            if(i >= c){
                dp[i] = min(dp[i], dp[i-c] + 1);
            }
        }
    }
    return dp[amount] == amount ? -1 : dp[amount];
}

int coinChange(vector<int>& coins, int m) {
    vector<int> f(m+1, 1e8);
    f[0] = 0;
    for(auto v : coins){
        for (int j = v; j <= m; j++){
            f[j] = min(f[j], f[j-v] + 1);
        }
    }
    if(f[m] == 1e8) return -1;
    return f[m];
}



int main(){
    string line;
    while(getline(cin, line)){
        auto coins = stringToIntegerVector(line);
        getline(cin, line);
        int amount = stringToInteger(line);
        int ret = coinChange(coins, amount);
        cout << to_string(ret) << endl;
    }
    return 0;
}

