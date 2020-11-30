class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        const int MOD = INT_MAX;
        vector<long long> f(target + 1);
        f[0] = 1;
        for(int i = 1; i <= target; i++){
            for(int j = 0; j < n; j++){
                if(i >= nums[j]){
                    f[i] = (f[i] + f[i-nums[j]]) % MOD;
                }
            }
        }
        return f[target];
    }
};