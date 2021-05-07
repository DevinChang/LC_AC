class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int m) {
        int n = A.size();
        vector<vector<double>> f(n+1, vector<double>(m+1, -1e9));
        f[0][0] = 0;
        vector<int> s(n+1);
        for(int i = 1; i <= n; i++) s[i] = s[i-1] + A[i-1];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                for(int k = 0; k < i; k++)
                    f[i][j] = max(f[i][j], f[k][j-1] + (s[i] - s[k]) / (double)(i-k));
            }
        }
        return f[n][m];
    }
};