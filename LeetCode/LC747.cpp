class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[k]) k = i;
        } 
        for(int i = 0; i < n; i++) {
            if(i != k && nums[k] < nums[i] * 2) return -1;
        }
        return k;
    }
};