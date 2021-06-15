class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
		int n = nums.size();
		vector<int> sum(n+1, 0), f(n+1, 0);
		for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + nums[i-1];
		f[0] = 1;
		int res = 0;
		for(int i = 1; i <= n; i++) {
			int s = sum[i];
			if(s >= goal) res += f[s - goal];
			f[s]++;
		}
		return res;
    }
};