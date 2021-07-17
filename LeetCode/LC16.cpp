class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		int res = 0, n = nums.size();
		res = nums[0] + nums[1] + nums[2];
		sort(nums.begin(), nums.end());
		for(int i = 0; i < n; i++) {
			int x = nums[i];
			for(int l = i + 1, r = n - 1; l < r; ) {
				int sum = nums[l] + nums[r] + x;
				if(abs(sum - target) < abs(res - target))
					res = sum;
				if(sum == target) return target;
				else if(sum < target) l++;	
				else r--;
			}
		}
		return res;
    }
};