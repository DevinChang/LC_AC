class Solution {
public:
    vector<int> p, s, c;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        for (int i = 0; i < n; i ++ ) {
            p.push_back(i);
            s.push_back(1);
            c.push_back(0);
        }
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < n; j ++ )
                if (graph[i][j] && find(i) != find(j)) {
                    s[find(i)] += s[find(j)];
                    p[find(j)] = find(i);
                }

        for (auto x: initial) c[find(x)] ++ ;

        int rs = -1, rp = INT_MAX;
        for (auto x: initial) {
            if (rs == -1) rp = min(rp, x);
            if (c[find(x)] == 1) {
                if (rs < s[find(x)]) {
                    rs = s[find(x)];
                    rp = x;
                } else if (rs == s[find(x)]) {
                    rp = min(rp, x);
                }
            }
        }
        return rp;
    }
};