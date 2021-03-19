class Solution {
public:
    int kInversePairs(int n, int k) {
        int mod = 1e9 + 7;
        vector<vector<int>> f(n+1, vector<int>(k+1));
        f[1][0] = 1;
        // f[i][j] 表示选择到第i个数能产生逆序对的数量
        // f[i][j] = f[i-1][j] + f[i-1][j-1] + .. + f[i-1][0]
        for (int i = 2; i <= n; i ++ ) {
            long long s = 0;
            for (int j = 0; j <= k; j ++ ) {
                s += f[i - 1][j];
                if (j - i >= 0) s -= f[i - 1][j - i];
                f[i][j] = s % mod;
            }
        }
        return (f[n][k] + mod) % mod;
    }
};