

bool canFinish(int n, vector<vector<int>> &prerequisites) {
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

    int cnt = 0;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        cnt ++ ;
        for (auto i : g[t])
            if ( -- d[i] == 0)
                q.push(i);
    }

    return cnt == n;
}