double f[25][25][101];
class Solution {
public:
    double knightProbability(int n, int K, int r, int c) {
        memset(f, 0, sizeof f);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) f[i][j][K] = 1;
        }
        int dx[] = {-2, -1,1,2,2,1,-1,-2};
        int dy[] = {1,2,2,1,-1,-2,-2,-1};
        for(int k = K-1; k >= 0; k--) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    for(int u = 0; u < 8; u++) {
                        int x = i + dx[u], y = j + dy[u];
                        if(x >= 0 && x < n && y >= 0 && y < n) f[i][j][k] += f[x][y][k+1] / 8;
                    }
                }
            }
        }
        return f[r][c][0];
    }
};