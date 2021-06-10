#define x first
#define y second

typedef pair<int, int> PII;

class Solution {
public:
    vector<vector<int>> id;
    vector<PII> cor;

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        id = vector<vector<int>>(n, vector<int>(m));
        cor = vector<PII>(n * m + 1);
        for (int i = n - 1, k = 1, s = 0; i >= 0; i --, s ++ ) {
            if (s % 2 == 0) {
                for (int j = 0; j < m; j ++, k ++ ) {
                    id[i][j] = k;
                    cor[k] = {i, j};
                }
            } else {
                for (int j = m - 1; j >= 0; j --, k ++ ) {
                    id[i][j] = k;
                    cor[k] = {i, j};
                }
            }
        }

        queue<PII> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        q.push({n - 1, 0});
        dist[n - 1][0] = 0;
        while (q.size()) {
            auto t = q.front();
            q.pop();

            int k = id[t.x][t.y];
            if (k == n * m) return dist[t.x][t.y];
            for (int i = k + 1; i <= k + 6 && i <= n * m; i ++ ) {
                int x = cor[i].x, y = cor[i].y;
                if (board[x][y] == -1) {
                    if (dist[x][y] > dist[t.x][t.y] + 1) {
                        dist[x][y] = dist[t.x][t.y] + 1;
                        q.push({x, y});
                    }
                } else {
                    int r = board[x][y];
                    x = cor[r].x, y = cor[r].y;
                    if (dist[x][y] > dist[t.x][t.y] + 1) {
                        dist[x][y] = dist[t.x][t.y] + 1;
                        q.push({x, y});
                    }
                }
            }
        }
        return -1;
    }
};