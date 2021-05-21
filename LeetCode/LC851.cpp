class Solution {
public:
    vector<vector<int>> g;
    vector<int> w;
    vector<int> ans;

    void dfs(int u){
        if(ans[u] != -1) return;
        ans[u] = u;
        for(auto v : g[u]) {
            dfs(v);
            if(w[ans[u]] > w[ans[v]]) ans[u] = ans[v];
        }
    } 

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        w = quiet;
        g.resize(n);
        ans.resize(n, -1);
        for(auto& e :richer) {
            int a = e[0], b = e[1];
            g[b].push_back(a);
        }
        for(int i = 0; i < n; i++) dfs(i);
        return ans;
    }
};