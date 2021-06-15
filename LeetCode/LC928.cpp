class Solution {
public:
    vector<int> p, s;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        p.resize(n), s.resize(n);
        for (int i = 0; i < n; i ++ ) p[i] = i, s[i] = 1;
        unordered_set<int> S(initial.begin(), initial.end());

        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < n; j ++ )
                if (!S.count(i) && !S.count(j) && graph[i][j] && find(i) != find(j)) {
                    s[find(i)] += s[find(j)];
                    p[find(j)] = find(i);
                }

		// 统计连通块的节点个数
        vector<unordered_set<int>> cnt(n);
        for (auto x: initial)
            for (int i = 0; i < n; i ++ )
                if (!S.count(i) && graph[x][i])
                    cnt[find(i)].insert(x);

		// 统计每个连通块连接的病毒个数
        unordered_set<int> comp;
        for (int i = 0; i < n; i ++ )
            if (!S.count(i))
                comp.insert(find(i));
		
        vector<int> sum(n);
        for (auto x: comp)
            if (cnt[x].size() == 1)
                sum[*cnt[x].begin()] += s[x];

        int res = initial[0];
        for (auto x: initial)
            if (sum[x] > sum[res] || sum[x] == sum[res] && x < res)
                res = x;
        return res;
    }
};