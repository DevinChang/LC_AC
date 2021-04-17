typedef pair<int, int> PII;

#define x first
#define y second

class Solution {
public:
    int n, m;
    vector<vector<int>> g;
    vector<vector<bool>> st;
    vector<PII> path;
    set<PII> S;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    int dfs(int x, int y) {
        st[x][y] = true;
        path.push_back({x, y});
        int res = 0;
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m) {
                if (!g[a][b]) S.insert({a, b}), res ++ ;
                else if (g[a][b] == 1 && !st[a][b])
                    res += dfs(a, b);
            }
        }
        return res;
    }

    int find() {
        st = vector<vector<bool>>(n, vector<bool>(m));
        int cnt = 0, res = 0;
        vector<PII> ps;
        vector<set<PII>> ss;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ ) 
                if (g[i][j] == 1 && !st[i][j]){
                    path.clear(), S.clear();
                    int t = dfs(i, j);
                    if (S.size() > cnt) {
                        cnt = S.size();
                        res = t;
                        ps = path;
                    }
                    ss.push_back(S);
                }
        for (auto& p: ps) g[p.x][p.y] = -1;
        for (auto& s: ss)
            if (s.size() != cnt)
                for (auto& p: s)
                    g[p.x][p.y] = 1;
        return res;
    }

    int containVirus(vector<vector<int>>& grid) {
        g = grid;
        n = g.size(), m = g[0].size();
        int res = 0;
        while (true) {
            auto cnt = find();
            if (!cnt) break;
            res += cnt;
        }
        return res;
    }
};