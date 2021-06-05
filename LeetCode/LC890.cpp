class Solution {
public:
    bool check(string& a, string& b) {
        unordered_map<char, char> f, g;
        for(int i = 0; i < a.size(); i++) {
            if(f.count(a[i]) && f[a[i]] != b[i]) return false;
            if(g.count(b[i]) && g[b[i]] != a[i]) return false;
            f[a[i]] = b[i], g[b[i]] = a[i];
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(auto& w : words) {
            if(check(w, pattern)) res.push_back(w);
        }
        return res;
    }
};