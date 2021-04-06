class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> cnt, minp, maxp;
        int d = 0;
        for (int i = 0; i < nums.size(); i ++ ) {
            int x = nums[i];
            d = max(d, ++ cnt[x]);
            if (!minp.count(x)) minp[x] = i;
            maxp[x] = i;
        }
        int res = INT_MAX;
        for (auto x: nums)
            if (cnt[x] == d)
                res = min(res, maxp[x] - minp[x] + 1);
        return res;
    }
};