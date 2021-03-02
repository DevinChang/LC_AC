#define x first
#define y second
typedef pair<int,int> PII;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return matrix;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<PII> q;

        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }

        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        while (q.size()) {
            auto t = q.front();
            q.pop();

            for (int i = 0; i < 4; i ++ ) {
                int x = t.x + dx[i], y = t.y + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < m && dist[x][y] == -1) {
                    dist[x][y] = dist[t.x][t.y] + 1;
                    q.push({x, y});
                }
            }
        }

        return dist;
    }
};