class Solution {
public:
    int numPermsDISequence(string s) {
        int n = s.size(), MOD = 1e9 + 7;
        vector<vector<int>> f(n + 1, vector<int>(n + 1));
        f[0][0] = 1;
        for (int i = 1; i <= n; i ++ ) {
            if (s[i - 1] == 'D') {
                for (int j = i - 1; j >= 0; j -- )
                    f[i][j] = (f[i - 1][j] + f[i][j + 1]) % MOD;
            } else {
                for (int j = 1; j <= i; j ++ )
                    f[i][j] = (f[i - 1][j - 1] + f[i][j - 1]) % MOD;
            }
        }
        int res = 0;
        for (int i = 0; i <= n; i ++ )
            res = (res + f[n][i]) % MOD;
        return res;
    }
};