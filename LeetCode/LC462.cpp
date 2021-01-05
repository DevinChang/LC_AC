class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(auto x : nums) {
            res += abs(x - nums[n/2]);
        }
        return res;
    }
};