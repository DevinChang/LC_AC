class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
		int n = nums.size(), cur = 0, res = 0;
		sort(nums.begin(), nums.end());
		for(int i = 0; i < n; i++) {
			if(nums[i] < cur) {
				res += cur - nums[i];
			} else {
				cur = nums[i];
			}
			cur++;
		}
		return res;
    }
};