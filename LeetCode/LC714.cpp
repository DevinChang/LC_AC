class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size(), INF = 1e8;
        vector<vector<int>> f(n+1, vector<int>(2, -INF));
        f[0][0] = 0;
        int res = 0;
        for(int i = 1; i <= n; i++) {
            f[i][0] = max(f[i-1][0], f[i-1][1]+prices[i-1]);
            f[i][1] = max(f[i-1][1], f[i-1][0] - prices[i-1] - fee);
            res = max(res, f[i][0]);
        }
        return res;
    }
};