//
// Created by devinchang on 2019/12/24.
//

#include "util.h"


int maxProfit(vector<int> &prices){
    int len = prices.size();
    if(len < 1)
        return 0;
    vector<vector<int>> dp(len, vector<int>(3, 0));
    for(int k = 1; k <= 2; k++){
        int minprice = prices[0];
        for(int i = 1; i < len; i++){
            minprice = min(minprice, prices[i] - dp[i-1][k-1]);
            dp[i][k] = max(dp[i-1][k], prices[i]-minprice);
        }
    }
    return dp[len-1][2];
}




int main(){
    string line;
    while(getline(cin, line)){
        vector<int> prices = stringToIntegerVector(line);
        int ret = maxProfit(prices);
        cout << ret << endl;
    }
    return 0;
}

