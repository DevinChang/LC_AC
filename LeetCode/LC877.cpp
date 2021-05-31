class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> f(n, vector<int>(n,0));
        for(len = 1; len <= n; len++) {
            for(int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if(len == 1) f[i][j] = piles[i];
                else {
                    f[i][j] = max(piles[i] - f[i+1][j], piles[j] - f[i][j-1]);
                }
            }
        }
        return f[0][n-1] > 0;
    }
};