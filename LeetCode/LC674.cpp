class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxl = 0, st = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i] <= nums[i-1]){
                maxl = max(maxl, i - st);
                st = i;
            }
        }
        return max(maxl, n - st);
    }
};