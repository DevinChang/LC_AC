


vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>> g(n);
        vector<int> d(n);
        for (auto& e: prerequisites) {
            int b = e[0], a = e[1];
            g[a].push_back(b);
            d[b] ++ ;
        }
        queue<int> q;
        for (int i = 0; i < n; i ++ )
            if (d[i] == 0)
                q.push(i);

        vector<int> res;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            res.push_back(t);
            for (int i: g[t])
                if ( -- d[i] == 0)
                    q.push(i);
        }
        if (res.size() < n) res = {};
        return res;
}