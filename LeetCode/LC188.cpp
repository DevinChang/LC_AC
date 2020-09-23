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

int maxProfit(int k, vector<int> &prices){
    const int INF = 1e8;
    int n = prices.size();
    if (k >= n / 2) {  // 等价于可以交易无限次
        int res = 0;
        for (int i = 0; i + 1 < n; i ++ )
            if (prices[i + 1] > prices[i])
                res += prices[i + 1] - prices[i];
        return res;
    }

    vector<vector<int>> f(2, vector<int>(k + 1, -INF));
    auto g = f;
    int res = 0;
    f[0][0] = 0;
    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j <= k; j ++ ) {
            f[i & 1][j] = max(f[i - 1 & 1][j], g[i - 1 & 1][j] + prices[i - 1]);
            g[i & 1][j] = g[i - 1 & 1][j];
            if (j) g[i & 1][j] = max(g[i & 1][j], f[i - 1 & 1][j - 1] - prices[i - 1]);
            res = max(res, f[i & 1][j]);
        }

    return res;
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

