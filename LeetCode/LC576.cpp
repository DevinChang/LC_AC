class Solution {
public:
    const int Mod = 1e9+7;
    int findPaths(int m, int n, int N, int x, int y) {
        if(!N) return 0;
        vector<vector<vector<int>>> f(m, vector<vector<int>>(n, vector<int>(N+1)));
        for(int i = 0; i < n; i++) {
            f[0][i][1]++;
            f[m-1][i][1]++;
        }
        for(int i = 0; i < m; i++) {
            f[i][0][1]++;
            f[i][n-1][1]++;
        }

        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        for(int k = 1; k <= N; k++) {
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    for(int u = 0; u < 4; u++) {
                        int a = i + dx[u], b = j + dy[u];
                        if(a >= 0 && a < m && b >= 0 && b < n){
                            (f[i][j][k] += f[a][b][k-1]) %= Mod;
                        }
                    }
                }
            }
        }
        int res = 0; 
        for(int k = 1; k <= N; k++) (res += f[x][y][k]) %= Mod;
        return res;
    }
};