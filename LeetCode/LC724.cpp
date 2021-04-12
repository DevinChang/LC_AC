class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        for(int i = 0, s = 0; i < nums.size(); i++) {
            if(s == sum - s - nums[i]) return i;
            s += nums[i];
        }
        return -1;
    }
};