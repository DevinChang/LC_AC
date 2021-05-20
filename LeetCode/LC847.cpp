class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(), INF = 1e8;
        vector<vector<int>> f(1 << n, vector<int>(n, INF));
        typedef pair<int,int> PII;

        #define x first
        #define y second

        queue<PII> q;
        for(int i = 0; i < n; i++){
            int x = 1 << i, y = i;
            f[x][y] = 0;
            q.push({x, y});
        }
        while(q.size()){
            auto t = q.front();
            q.pop();
            for(auto z : graph[t.y]){
                int a = t.x | 1 << z, b = z;
                if(f[a][b] > f[t.x][t.y] + 1) {
                    f[a][b] = f[t.x][t.y] + 1;
                    q.push({a, b});
                }
            }
        }
        int res = INF;
        for(int i = 0; i < n; i++) {
            res = min(res, f[(1 << n) - 1][i]);
        }
        return res;
    }
};