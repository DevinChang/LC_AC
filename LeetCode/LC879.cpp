class Solution {
public:
    int profitableSchemes(int n, int m, vector<int>& group, vector<int>& profit) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> f(n+1, vector<int>(m+1));
        for(int i = 0; i <= n; i++) f[i][0] = 1;
        for(int i = 0; i < group.size(); i++) {
            int g = group[i], p = profit[i];
            for(int j = n; j >= g; j--) {
                for(int k = m; k >= 0; k--) 
                    f[j][k] = (f[j][k] + f[j-g][max(0, k - p)]) % MOD;
            }
        }
        return f[n][m];
    }
};