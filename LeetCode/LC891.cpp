typedef long long LL;
const int N = 20010, MOD = 1e9+7;

int p[N];

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        int n = nums.size();
        p[0] = 1;
        for(int i = 1; i <= n; i++) p[i] = p[i-1] * 2 % MOD;
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) 
            res = (res + (LL)nums[i] * p[i] - (LL)nums[i] * p[n-i-1]) % MOD;
        return res;
    }
};