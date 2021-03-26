class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        if (!n) return 0;
        vector<vector<int>> f(n + 1, vector<int>(n + 1));
        for (int len = 1; len <= n; len ++ )
            for (int i = 0; i + len - 1 < n; i ++ ) {
                int j = i + len - 1;
                f[i][j] = 1 + f[i + 1][j];
                for (int k = i + 1; k <= j; k ++ )
                    if (s[k] == s[i])
                        f[i][j] = min(f[i][j], f[i][k - 1] + f[k + 1][j]);
            }
        return f[0][n - 1];
    }
};