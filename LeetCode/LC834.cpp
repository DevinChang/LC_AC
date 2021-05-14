const int N = 10010, M = 20010;

int h[N], e[M], ne[M], idx;
int sum[N], cnt[N], up[N];

class Solution {
public:
    int n;

    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
    }

    void dfs1(int u, int father) {
        sum[u] = 0;
        cnt[u] = 1;
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (j == father) continue;
            dfs1(j, u);
            sum[u] += sum[j] + cnt[j];
            cnt[u] += cnt[j];
        }
    }

    void dfs2(int u, int father) {
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (j == father) continue;
            up[j] = up[u] + sum[u] - (sum[j] + cnt[j]) + n - cnt[j];
            dfs2(j, u);
        }
    }

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        memset(h, -1, sizeof h);
        idx = 0;
        n = N;
        for (auto& e: edges) {
            int a = e[0], b = e[1];
            add(a, b), add(b, a);
        }

        dfs1(0, -1);
        dfs2(0, -1);

        vector<int> res;
        for (int i = 0; i < n; i ++ )
            res.push_back(sum[i] + up[i]);
        return res;
    }
};