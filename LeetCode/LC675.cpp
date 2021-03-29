class Solution {
public:
    struct Tree {
        int x, y, h;
        bool operator< (const Tree& t) const {
            return h < t.h;
        }
    };
    int n, m;
    vector<vector<int>> g;

    int bfs(Tree start, Tree end) {
        if (start.x == end.x && start.y == end.y) return 0;
        queue<Tree> q;
        const int INF = 1e8;
        vector<vector<int>> dist(n, vector<int>(m, INF));
        dist[start.x][start.y] = 0;
        q.push({start});
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        while (q.size()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i ++ ) {
                int x = t.x + dx[i], y = t.y + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < m && g[x][y]) {
                    if (dist[x][y] > dist[t.x][t.y] + 1) {
                        dist[x][y] = dist[t.x][t.y] + 1;
                        if (x == end.x && y == end.y) return dist[x][y];
                        q.push({x, y});
                    }
                }
            }
        }
        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        g = forest;
        n = g.size(), m = g[0].size();
        vector<Tree> trs;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (g[i][j] > 1)
                    trs.push_back({i, j, g[i][j]});
        sort(trs.begin(), trs.end());
        Tree last = {0, 0};
        int res = 0;
        for (auto& tr: trs) {
            int t = bfs(last, tr);
            if (t == -1) return -1;
            res += t;
            last = tr;
        }
        return res;
    }
};