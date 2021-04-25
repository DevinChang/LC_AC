class Solution {
public:
    const int INF = 1e8;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dist(n, INF);
        dist[src] = 0;
        K++;
        while(K--) {
            auto cur = dist;
            for(auto& e : flights) {
                int a = e[0], b = e[1], c = e[2];
                cur[b] = min(cur[b], dist[a] + c);
            }
            dist = cur;
        }
        if(dist[dst] == INF) return -1;
        return dist[dst];
    }
};