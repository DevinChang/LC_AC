class Solution {
public:
    vector<string> res;
    vector<string> letterCasePermutation(string S) {
        int u = 0;
        dfs(S, u);
        return res;
    }
    void dfs(string &s, int u) {
        if(u == s.size()) {
            res.push_back(s);
            return;
        }
        dfs(s, u+1);
        if(!isdigit(s[u])) {
            s[u] ^= 32;
            dfs(s, u+1);
            s[u] ^= 32;
        }
    }
};