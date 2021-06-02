const int N = 3010, M = 20010, INF = 0x3f3f3f3f;

int h[N], e[M], w[M], ne[M], idx;
int dist[N], q[N];
bool st[N];

class Solution {
public:
    void add(int a, int b, int c) {
        e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
    }

    void spfa() {
        memset(dist, 0x3f, sizeof dist);
        dist[0] = 0;
        int hh = 0, tt = 1;
        q[0] = 0;
        while (hh != tt) {
            int t = q[hh ++ ];
            if (hh == N) hh = 0;
            st[t] = false;

            for (int i = h[t]; ~i; i = ne[i]) {
                int j = e[i];
                if (dist[j] > dist[t] + w[i]) {
                    dist[j] = dist[t] + w[i];
                    if (!st[j]) {
                        q[tt ++ ] = j;
                        if (tt == N) tt = 0;
                        st[j] = true;
                    }
                }
            }
        }
    }

    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        memset(h, -1, sizeof h);
        idx = 0;
        for (auto& e: edges) {
            int a = e[0], b = e[1], c = e[2];
            add(a, b, c + 1), add(b, a, c + 1);
        }
        spfa();

        int res = 0;
        for (int i = 0; i < n; i ++ )
            if (dist[i] <= maxMoves)
                res ++ ;

        for (auto& e: edges) {
            int a = e[0], b = e[1], c = e[2];
            int x = max(0, maxMoves - dist[a]), y = max(0, maxMoves - dist[b]);
            res += min(x + y, c);
        }
        return res;
    }
};