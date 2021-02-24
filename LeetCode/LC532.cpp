class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        for(int i = 0, j = 0; i < n;i++) {
            while(i + 1 < n && nums[i] == nums[i+1]) i++;
            while(j < i & nums[i] - nums[j] > k) j++;
            if(i > j && nums[i] - nums[j] == k) res++;
        }
        return res;
    }
};