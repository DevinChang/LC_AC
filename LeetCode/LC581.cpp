class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n - 1;
        if(n == 1) return 0;
        while(l+1 < n && nums[l+1] >= nums[l]) l++;
        if (l == r) return 0;
        while(r - 1 >= 0 && nums[r-1] <= nums[r]) r--;
        for(int i = l + 1; i < n; i++) {
            while(l >= 0 && nums[i] < nums[l]) l--;
        }
        for(int i = r - 1; i >= 0; i--) {
            while(r < n && nums[i] > nums[r]) r++;
        }
        return r - l - 1;
    }
};