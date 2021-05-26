int dist[31][31][64];

class Solution {
public:
    struct Node {
        int x, y, s;
    };

    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size(), S = 0;
        memset(dist, 0x3f, sizeof dist);
        queue<Node> q;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (grid[i][j] == '@') {
                    dist[i][j][0] = 0;
                    q.push({i, j, 0});
                } else if (grid[i][j] >= 'A' && grid[i][j] <= 'Z') {
                    S ++ ;
                }

        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        while (q.size()) {
            auto t = q.front();
            q.pop();
            int d = dist[t.x][t.y][t.s];

            for (int i = 0; i < 4; i ++ ) {
                int x = t.x + dx[i], y = t.y + dy[i], s = t.s;
                if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#') continue;
                char c = grid[x][y];
                if (c >= 'a' && c <= 'z') {
                    s |= 1 << c - 'a';
                    if (dist[x][y][s] > d + 1) {
                        dist[x][y][s] = d + 1;
                        if (s == (1 << S) - 1) return d + 1;
                        q.push({x, y, s});
                    }
                } else if (c >= 'A' && c <= 'Z') {
                    if (s & (1 << c - 'A')) {
                        if (dist[x][y][s] > d + 1) {
                            dist[x][y][s] = d + 1;
                            q.push({x, y, s});
                        }
                    }
                } else {
                    if (dist[x][y][s] > d + 1) {
                        dist[x][y][s] = d + 1;
                        q.push({x, y, s});
                    }
                }
            }
        }
        return -1;
    }
};