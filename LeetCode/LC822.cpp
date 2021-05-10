class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> S;
        for(int i = 0; i < fronts.size(); i++) {
            if(fronts[i] == backs[i]) S.insert(fronts[i]);
        }
        int res = INT_MAX;
        for(auto x : fronts) {
            if(!S.count(x)) res = min(res, x);
        }
        for(auto x : backs) {
            if(!S.count(x)) res = min(res, x);
        }
        if(res == INT_MAX) res = 0;
        return res;
    }
};