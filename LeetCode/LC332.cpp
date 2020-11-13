class Solution {
public:
    vectorstring> ans;
    unordered_map<string, multiset<string>> g;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &t : tickets) g[t[0]].insert(t[1]);
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void dfs(string u) {
        while(g[u].size()){
            auto ver = *g[u].begin();
            g[u].erase(g[u].begin());
            dfs(ver);
        }
        ans.push_back(u);
    }
};