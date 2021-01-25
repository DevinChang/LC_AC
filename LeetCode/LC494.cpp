class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        // sum做为偏移量
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(!(-sum <= S && S <= sum)) return 0;
        vector<vector<int>> f(n+1, vector<int>(2 * sum + 1, 0));
        f[0][0 + sum] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = -sum; j <= sum; j++) {
                if(-sum <= j- nums[i-1]) f[i][j+sum] += f[i-1][j-nums[i-1] + sum];
                if(j + nums[i-1] <= sum) f[i][j+sum] += f[i-1][j+nums[i-1] + sum];
            }
        }
        return f[n][S+sum];
    }
};