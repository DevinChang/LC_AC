class Solution {
public:
    int n, m;
    vector<vector<int>> g;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    int dfs(int x, int y) {
        int res = 1;
        g[x][y] = 0;
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && g[a][b])
                res += dfs(a, b);
        }
        return res;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        g = grid;
        n = g.size(), m = g[0].size();
        int res = 0;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (g[i][j]) {
                    res = max(res, dfs(i, j));
                }
        return res;
    }
};