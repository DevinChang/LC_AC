class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> r(n, nums[n-1]);
        for(int i = n - 2; i >= 0; i--) r[i] = min(nums[i], r[i+1]);

        for(int i = 0, l = INT_MIN; i < n-1; i++) {
            l = max(l, nums[i]);
            if(l <= r[i+1]) return i+1;
        }
        return -1;
    }
};