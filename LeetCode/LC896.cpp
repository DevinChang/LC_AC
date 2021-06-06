class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool x = true, y = true;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i-1] > nums[i]) x = false;
            if(nums[i-1] < nums[i]) y = false;
        }
        return x || y;
    }
};