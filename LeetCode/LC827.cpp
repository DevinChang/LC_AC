class Solution {
public:
    int n, m;
    vector<int> p, sz;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    int get(int x, int y) {
        return x * m + y;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n * m; i ++ ) p.push_back(i), sz.push_back(1);

        int res = 1;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (grid[i][j]) {
                    int a = get(i, j);
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
                    res = max(res, sz[find(a)]);
                }

        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (!grid[i][j]) {
                    map<int, int> hash;
                    for (int k = 0; k < 4; k ++ ) {
                        int x = i + dx[k], y = j + dy[k];
                        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y]) {
                            int a = get(x, y);
                            hash[find(a)] = sz[find(a)];
                        }
                    }
                    int s = 1;
                    for (auto [k, v]: hash) s += v;
                    res = max(res, s);
                }
        return res;
    }
};