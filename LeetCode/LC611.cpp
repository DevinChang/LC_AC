class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i-1, k = 0; j > k; j--) {
                while(j > k && nums[k] + nums[j] <= nums[i]) k++;
                res += j - k;
            }
        }
        return res;
    }
};