class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minv = INT_MAX;
        for(auto x : nums) minv = min(minv, x);
        int res = 0;
        for(auto x : nums) res += x - minv;
        return res;
    }
};