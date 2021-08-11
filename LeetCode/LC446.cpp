class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
		int n = nums.size();
		typedef long long LL;
		int res = 0;
		// f[i][j]表示以nums[i]结尾的，公差为j的个数
		vector<unordered_map<LL,int>> f(n);
		for(int i = 0; i < n; i ++) {
			for(int k = 0; k < i; k++) {
				// 公差
				LL j = (LL)nums[i] - nums[k];
				// 查找f[k][j]是否被计算过
				auto it = f[k].find(j); 
				int t = 0;
				// 已经存在
				if(it != f[k].end()) {
					t = it->second;
					res += t;
				}
				// f[i][j] = f[k][j] + 1
				f[i][j] += t + 1;
			}
		}
		return res;
    }
};