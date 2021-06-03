class Solution {
public:
    vector<vector<int>> g;
    vector<int> color;

    bool dfs(int u, int c) {
        color[u] = c;
        for(int v : g[u]) {
            if(color[v]){
                if(color[v] == c) return false;
            } else if (!dfs(v, 3-c)) return false;
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        g.resize(n);
        color.resize(n);
        for(auto &e : dislikes) {
            int a = e[0] - 1, b = e[1] - 1;
            g[a].push_back(b), g[b].push_back(a);
        }
        for(int i = 0; i < n; i++) {
            if(!color[i] && !dfs(i, 1)) return false;
        }
        return true;
    }
};