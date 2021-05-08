int dist[20010][15][2];

class Solution {
public:
    struct Node {
        int x, k, d;
    };

    int racecar(int target) {
        memset(dist, 0x3f, sizeof dist);
        queue<Node> q;
        dist[0][0][1] = 0;
        q.push({0, 0, 1});
        while (q.size()) {
            auto t = q.front();
            q.pop();

            int distance = dist[t.x][t.k][t.d];
            int x = t.x + (1 << t.k) * (t.d * 2 - 1);
            if (x >= 0 && x <= target * 2) {
                int k = t.k + 1, d = t.d;
                if (dist[x][k][d] > distance + 1) {
                    dist[x][k][d] = distance + 1;
                    if (x == target) return distance + 1;
                    q.push({x, k, d});
                }
            }

            x = t.x;
            int k = 0, d = t.d ^ 1;
            if (dist[x][k][d] > distance + 1) {
                dist[x][k][d] = distance + 1;
                q.push({x, k, d});
            }
        }
        return -1;
    }
};