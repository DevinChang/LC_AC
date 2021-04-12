class Solution {
public:
    vector<int> p;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        for (int i = 0; i < n; i ++ ) p.push_back(i);
        unordered_map<string, vector<int>> hash;
        for (int i = 0; i < n; i ++ ) {
            for (int j = 1; j < accounts[i].size(); j ++ )
                hash[accounts[i][j]].push_back(i);
        }
        for (auto& [k, v]: hash)
            for (int i = 1; i < v.size(); i ++ )
                p[find(v[i])] = find(v[0]);
        vector<set<string>> res(n);
        for (int i = 0; i < n; i ++ )
            for (int j = 1; j < accounts[i].size(); j ++ )
                res[find(i)].insert(accounts[i][j]);
        vector<vector<string>> ans;
        for (int i = 0; i < n; i ++ )
            if (res[i].size()) {
                vector<string> t;
                t.push_back(accounts[i][0]);
                for (auto& e: res[i]) t.push_back(e);
                ans.push_back(t);
            }
        return ans;
    }
};