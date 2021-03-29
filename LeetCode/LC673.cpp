class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 0, maxl = 1;
        vector<int> f(n, 1), g(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    if(f[i] < f[j] + 1){
                        f[i] = f[j] + 1;
                        g[i] = g[j];
                    } else if(f[i] == f[j]+1){
                        g[i] += g[j];
                    }
                }
            }
            maxl = max(maxl, f[i]);
        }
        for(int i = 0; i < n; i++) {
            if(f[i] == maxl) res += g[i];
        }
        return res;
    }
};