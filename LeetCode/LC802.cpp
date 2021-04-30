class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> d(n);
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i ++ )
            for (auto b: graph[i]) {
                int a = i;
                g[b].push_back(a);
                d[a] ++ ;
            }
        queue<int> q;
        for (int i = 0; i < n; i ++ )
            if (!d[i])
                q.push(i);
        while (q.size()) {
            auto t = q.front();
            q.pop();
            for (auto u: g[t])
                if ( -- d[u] == 0)
                    q.push(u);
        }
        vector<int> res;
        for (int i = 0; i < n; i ++ )
            if (!d[i])
                res.push_back(i);
        return res;
    }
};