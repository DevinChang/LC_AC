const int N = 510;

int f[N][N];
bool g[N][N];

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        memset(g, 1, sizeof g);
        for (auto& e: mines) g[e[0]][e[1]] = false;
        for (int i = 0; i < N; i ++ )
            for (int j = 0, s = 0; j < N; j ++ ) {
                if (g[i][j]) s ++ ;
                else s = 0;
                f[i][j] = s;
            }
        for (int i = 0; i < N; i ++ )
            for (int j = N - 1, s = 0; j >= 0; j -- ) {
                if (g[i][j]) s ++ ;
                else s = 0;
                f[i][j] = min(f[i][j], s);
            }
        for (int i = 0; i < N; i ++ )
            for (int j = 0, s = 0; j < N; j ++ ) {
                if (g[j][i]) s ++ ;
                else s = 0;
                f[j][i] = min(f[j][i], s);
            }
        for (int i = 0; i < N; i ++ )
            for (int j = N - 1, s = 0; j >= 0; j -- ) {
                if (g[j][i]) s ++ ;
                else s = 0;
                f[j][i] = min(f[j][i], s);
            }
        int res = 0;
        for (int i = 0; i < N; i ++ )
            for (int j = 0; j < N; j ++ )
                res = max(res, f[i][j]);
        return res;
    }
};