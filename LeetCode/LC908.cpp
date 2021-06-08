class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minw = INT_MAX, maxw = INT_MIN;
        for (auto x: nums) {
            minw = min(minw, x);
            maxw = max(maxw, x);
        }
        return max(0, maxw - minw - k * 2);
    }
};