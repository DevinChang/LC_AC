const int N = 110, M = 6010, INF = 0x3f3f3f3f;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];

class Solution {
public:
    void add(int a, int b, int c) {
        e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
    }

    void spfa(int start) {
        queue<int> q;
        q.push(start);
        memset(dist, 0x3f, sizeof dist);
        dist[start] = 0;
        while (q.size()) {
            int t = q.front();
            q.pop();
            st[t] = false;
            for (int i = h[t]; ~i; i = ne[i]) {
                int j = e[i];
                if (dist[j] > dist[t] + w[i]) {
                    dist[j] = dist[t] + w[i];
                    if (!st[j]) {
                        q.push(j);
                        st[j] = true;
                    }
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        memset(h, -1, sizeof h);
        idx = 0;
        for (auto& e: times) {
            int a = e[0], b = e[1], c = e[2];
            add(a, b, c);
        }
        spfa(k);
        int res = 1;
        for (int i = 1; i <= n; i ++ ) res = max(res, dist[i]);
        if (res == INF) res = -1;
        return res;
    }
};