class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        int s1 = accumulate(a.begin(), a.end(), 0);
        int s2 = accumulate(b.begin(), b.end(), 0);
        unordered_set<int> S;
        for(auto x : b) S.insert(x);
        int t = (s1 - s2) / 2;
        for(auto x : a) {
            if(S.count(x - t)) return {x, x-t};
        }
        return {};
    }
};