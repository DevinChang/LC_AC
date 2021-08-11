class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for(int i = n - 1; i > 0; i--) nums[i] -= nums[i-1];
        for(int i = 1; i < n; i++) {
            int j = i;
            while(j < n && nums[j] == nums[i]) j++;
            int k = j - i;
            res += (k - 1) * k / 2;
            i = j - 1;
        }
        return res;
    }
};