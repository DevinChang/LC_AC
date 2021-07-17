class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		int n = nums.size();
		if(n < 1) return res;
        sort(nums.begin(), nums.end());
		for(int i = 0; i < n; i++) {
			if(i && nums[i] == nums[i-1]) continue;
			int x = nums[i];
			for(int l = i + 1, r = n-1; l < r; l++) {
				if(l > i + 1 && nums[l] == nums[l-1]) continue;
				while(l < r - 1 && nums[l] + nums[r-1] + x >= 0) r--;
				if(nums[l] + nums[r] + x == 0) {
                    res.push_back({x, nums[l], nums[r]});
                };
			}
		}
		return res;
    }
};