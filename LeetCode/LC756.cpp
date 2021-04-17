class Solution {
public:
    vector<char> g[7][7];

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(auto& s : allowed) g[s[0]-'A'][s[1]-'A'].push_back(s[2]);
        return dfs(bottom, "", 0);
    }

    bool dfs(string bottom, string up, int u) {
        if(bottom.size() == 1) return true;
        if(u == bottom.size()-1) return dfs(up, "", 0);
        for(auto c : g[bottom[u]-'A'][bottom[u+1]-'A']) {
            if(dfs(bottom, up+c, u+1)) return true;
        }
        return false;
    }
};