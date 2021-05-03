class Solution {
public:
    int n, m;
    vector<int> p, sz;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    int get(int x, int y) {
        return x * m + y;
    }

    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        n = grid.size(), m = grid[0].size();
        int S = n * m;
        for (int i = 0; i <= S; i ++ ) p.push_back(i), sz.push_back(1);

        vector<bool> st;
        for (auto& p: hits) {
            int x = p[0], y = p[1];
            if (grid[x][y]) {
                grid[x][y] = 0;
                st.push_back(true);
            } else {
                st.push_back(false);
            }
        }

        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (grid[i][j]) {
                    int a = get(i, j);
                    if (!i) {
                        if (find(S) != find(a)) {
                            sz[find(S)] += sz[find(a)];
                            p[find(a)] = find(S);
                        }
                    }
                    for (int k = 0; k < 4; k ++ ) {
                        int x = i + dx[k], y = j + dy[k];
                        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y]) {
                            int b = get(x, y);
                            if (find(a) != find(b)) {
                                sz[find(b)] += sz[find(a)];
                                p[find(a)] = find(b);
                            }
                        }
                    }
                }

        vector<int> res(hits.size());
        int last = sz[find(S)];
        for (int i = hits.size() - 1; i >= 0; i -- )
            if (st[i]) {
                int x = hits[i][0], y = hits[i][1];
                grid[x][y] = 1;
                int a = get(x, y);
                if (!x) {
                    if (find(S) != find(a)) {
                        sz[find(S)] += sz[find(a)];
                        p[find(a)] = find(S);
                    }
                }
                for (int j = 0; j < 4; j ++ ) {
                    int c = x + dx[j], d = y + dy[j];
                    if (c >= 0 && c < n && d >= 0 && d < m && grid[c][d]) {
                        int b = get(c, d);
                        if (find(a) != find(b)) {
                            sz[find(b)] += sz[find(a)];
                            p[find(a)] = find(b);
                        }
                    }
                }

                res[i] = max(0, sz[find(S)] - last - 1);
                last = sz[find(S)];
            }
        return res;
    }
};