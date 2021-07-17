class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int n = nums.size();
		vector<vector<int>> res;
		if(n < 1) return res;
		sort(nums.begin(), nums.end());
		for(int i = 0; i < n; i++) {
			if(i && nums[i] == nums[i-1]) continue;
			for(int j = i + 1; j < n; j++) {
				if(j > i + 1 && nums[j] == nums[j-1]) continue;
				for(int l = j + 1, r = n - 1; l < r; l++) {
					if(l > j + 1 && nums[l] == nums[l-1])  continue;
					while(r - 1 > l && nums[l] + nums[r-1] + nums[i] + nums[j] >= target) r--;
					if(nums[i] + nums[j] + nums[l] + nums[r] == target)
						res.push_back({nums[i], nums[j], nums[l], nums[r]});
				}
			}
		}
		return res;
    }
};