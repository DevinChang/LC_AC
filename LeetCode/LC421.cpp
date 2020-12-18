class Solution {
public:
    vector<vector<int>> s;

    void insert(int x) {
        int p = 0;
        for(int i = 30; i >= 0; i--) {
            int u = x >> i & 1;
            if(!s[p][u]) s[p][u] = s.size(), s.push_back({0, 0});
            p = s[p][u];
        }
    }


    int query(int x) {
        int p = 0, res = 0;
        for(int i = 30; i >= 0; i--) {
            int u = x >> i & 1;
            if(s[p][!u]) p = s[p][!u], res = res * 2 + !u;
            else p = s[p][u], res = res * 2 + u;
        }
        return res ^ x;
    }

    int findMaximumXOR(vector<int>& nums) {
        s.push_back({0,0});
        int res = 0;
        for(auto x : nums) {
            res = max(res, query(x));
            insert(x);
        }
        return res;
    }
};