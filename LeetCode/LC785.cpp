class Solution {
public:
    vector<int> color;
    vector<vector<int>> g;

    bool dfs(int u, int c) {
        color[u] = c;
        for (auto v: g[u]) {
            if (color[v] != -1) {
                if (color[v] == c) return false;
            } else if (!dfs(v, c ^ 1)) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        g = graph;
        color = vector<int>(g.size(), -1);

        for (int i = 0; i < g.size(); i ++ )
            if (color[i] == -1)
                if (!dfs(i, 0))
                    return false;
        return true;
    }
};