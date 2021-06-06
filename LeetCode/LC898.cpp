class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res, f, g;
        for(auto x : arr) {
            g.insert(x);
            for(auto y : f) g.insert(x | y);
            for(auto y : g) res.insert(y);
            f = g, g.clear();
        }
        return res.size();
    }
};