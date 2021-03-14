class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> f(n+1, vector<int>(m+1, 0));
        for(int i = 0; i <= n; i++) f[i][0] = i;
        for(int i = 0; i <= m; i++) f[0][i] = i;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(word1[i-1] == word2[j-1]) f[i][j] = f[i-1][j-1];
                else {
                    f[i][j] = min(f[i-1][j], f[i][j-1]) + 1;
                }
            }
        }
        return f[n][m];
    }
};