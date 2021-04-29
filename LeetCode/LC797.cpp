class Solution {
public:
    vector<vector<int>> g;
    vector<vector<int>> res;
    vector<int> path;
    int n;
    void dfs(int u) {
        path.push_back(u);
        if(u == n - 1) res.push_back(path);
        for(auto v : g[u]) dfs(v);
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        g = graph;
        n = graph.size();
        int u = 0;
        dfs(u);
        return res;
    }
};