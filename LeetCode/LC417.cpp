class Solution {
public:
    int n, m;
    vector<vector<int>> w;
    vector<vector<int>> st;

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    void dfs(int x, int y, int t) {
        if(st[x][y] & t) return;
        st[x][y] |= t;
        for(int i = 0; i < 4; i++) {
            int a = x + dx[i] , b = y + dy[i];
            if(a >= 0 && a < n && b >= 0 && b < m && w[a][b] >= w[x][y]) dfs(a, b, t);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        w = matrix;
        if(w.empty() || w[0].empty()) return {};
        n  = w.size(), m = w[0].size();
        st = vector<vector<int>>(n, vector<int>(m));

        for(int i = 0; i < n; i++) dfs(i, 0, 1);
        for(int i = 0; i < m; i++) dfs(0, i, 1);
        for(int i = 0; i < n; i++) dfs(i, m-1, 2);
        for(int i = 0; i < m; i++) dfs(n-1, i, 2);

        vector<vector<int>> res;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(st[i][j] == 3) res.push_back({i, j});
            }
        }
        return res;
    }
};