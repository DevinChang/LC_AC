class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> f(n + 2, vector<int>(n + 2));
        for (int len = 2; len <= n; len ++ )
            for (int i = 1; i + len - 1 <= n; i ++ ) {
                int j = i + len - 1;
                f[i][j] = INT_MAX;
                for (int k = i; k <= j; k ++ )
                    f[i][j] = min(f[i][j], max(f[i][k - 1], f[k + 1][j]) + k);
            }
        return f[1][n];
    }
};