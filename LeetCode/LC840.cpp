class Solution {
public:
    int n, m;
    vector<vector<int>> g;

    bool check(int x, int y) {
        bool st[10] = {0};
        for (int i = x; i < x + 3; i ++ )
            for (int j = y; j < y + 3; j ++ ) {
                int t = g[i][j];
                if (t < 1 || t > 9) return false;
                if (st[t]) return false;
                st[t] = true;
            }

        for (int i = 0; i < 3; i ++ ) {
            if (g[x + i][y] + g[x + i][y + 1] + g[x + i][y + 2] != 15) return false;
            if (g[x][y + i] + g[x + 1][y + i] + g[x + 2][y + i] != 15) return false;
        }

        if (g[x][y] + g[x + 1][y + 1] + g[x + 2][y + 2] != 15) return false;
        if (g[x + 2][y] + g[x + 1][y + 1] + g[x][y + 2] != 15) return false;
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        g = grid;
        n = g.size(), m = g[0].size();
        int res = 0;
        for (int i = 0; i + 3 <= n; i ++ )
            for (int j = 0; j + 3 <= m; j ++ )
                if (check(i, j))
                    res ++ ;
        return res;
    }
};