class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> f(n, vector<int>(n, 0));
        for(int len = 1; len <= n; len++) {
            for(int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if(len == 1) f[i][j] = nums[i];
                else {
                    f[i][j] = max(-f[i+1][j] + nums[i], -f[i][j-1]+ nums[j]);
                }
            }
        }
        return f[0][n-1] >= 0;
    }
};