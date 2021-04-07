class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() -1;
        while(l < r) {
            int mid = (l + r) >>  1;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if(nums[r] != target) return -1;
        return r;
    }
};