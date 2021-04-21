class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<int> S(jewels.begin(), jewels.end());
        int res = 0;
        for(auto x : stones) {
            if(S.count(x)) res++;
        }
        return res;
    }
};