class Solution {
public:
    int n, m;
    vector<vector<int>> f, g;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    int dp(int x, int y)
    {
        if (f[x][y] != -1) return f[x][y];
        f[x][y] = 1;
        for (int i = 0; i < 4; i ++ )
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && g[a][b] < g[x][y])
                f[x][y] = max(f[x][y], dp(a, b) + 1);
        }
        return f[x][y];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        g = matrix;
        n = g.size(), m = g[0].size();
        f = vector<vector<int>>(n, vector<int>(m, -1));
        int res = 0;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                res = max(res, dp(i, j));
        return res;
    }
};