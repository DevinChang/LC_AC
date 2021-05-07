class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        int n = routes.size();
        unordered_map<int, vector<int>> g;
        vector<int> dist(n, 1e8);
        queue<int> q;
        for (int i = 0; i < n; i ++ ) {
            for (int x: routes[i]) {
                if (x == source) {
                    dist[i] = 1;
                    q.push(i);
                }
                g[x].push_back(i);
            }
        }
        while (q.size()) {
            int t = q.front();
            q.pop();

            for (auto x: routes[t]) {
                if (x == target) return dist[t];
                for (auto y: g[x]) {
                    if (dist[y] > dist[t] + 1) {
                        dist[y] = dist[t] + 1;
                        q.push(y);
                    }
                }
                g.erase(x);
            }
        }
        return -1;
    }
};