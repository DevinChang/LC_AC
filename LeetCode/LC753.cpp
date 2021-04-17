class Solution {
public:
    unordered_set<string> S;
    string ans;
    int k;

    void dfs(string u) {
        for (int i = 0; i < k; i ++ ) {
            auto v = u + to_string(i);
            if (!S.count(v)) {
                S.insert(v);
                dfs(v.substr(1));
                ans += to_string(i);
            }
        }
    }

    string crackSafe(int n, int _k) {
        k = _k;
        string start(n - 1, '0');
        dfs(start);
        return ans + start;
    }
};