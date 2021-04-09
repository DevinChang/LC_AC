class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int product = 1;
        int res = 0;
        for(int i = 0, j = 0; i < n; i++) {
            product *= nums[i];
            while(j <= i && product >= k) {
                product /= nums[j];
                j++;
            }
            res += i - j + 1;
        }
        return res;
    }
};