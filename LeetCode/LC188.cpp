//
// Created by devinchang on 2019/12/30.
//
#include "util.h"



int maxProfit(int k, vector<int>& prices){
    int len = prices.size();
    if(k < 1 || len < 1)
        return 0;
    if(k >= len / 2){
        int maxprofit = 0;
        for(int i = 1; i < len; i++){
            if(prices[i] > prices[i-1])
                maxprofit += prices[i] - prices[i-1];
        }
        return maxprofit;
    }
    vector<vector<int>> dp(len, vector<int>(k+1, 0));
    for(int j = 1; j <= k; j++){
        int minprice = prices[0];
        for(int i = 1; i < len; i++){
            minprice = min(minprice, prices[i]-dp[i-1][j-1]);
            dp[i][j] = max(dp[i-1][j], prices[i]-minprice);
        }
    }
    return dp[len-1][k];
}




int main(){
    string line;
    while(getline(cin, line)){
        int k = stringToInteger(line);
        getline(cin, line);
        vector<int> prices = stringToIntegerVector(line);
        int ret = maxProfit(k, prices);
        cout << to_string(ret) << endl;
    }

    return 0;
}

