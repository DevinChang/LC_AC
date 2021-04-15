const int N = 55;
int f[N][N][N * 2];

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        memset(f, -0x3f, sizeof f);
        if (grid[0][0] != -1) f[1][1][2] = grid[0][0];
        for (int k = 3; k <= n * 2; k ++ )
            for (int i = max(1, k - n); i <= min(n, k - 1); i ++ )
                for (int j = max(1, k - n); j <= min(n, k - 1); j ++ ) {
                    if (grid[i - 1][k - i - 1] == -1 || grid[j - 1][k - j - 1] == -1) continue;
                    int t = grid[i - 1][k - i - 1];
                    if (i != j) t += grid[j - 1][k - j - 1];
                    for (int a = i - 1; a <= i; a ++ )
                        for (int b = j - 1; b <= j; b ++ )
                            f[i][j][k] = max(f[i][j][k], f[a][b][k - 1] + t);
                }
        return max(0, f[n][n][n * 2]);
    }
};