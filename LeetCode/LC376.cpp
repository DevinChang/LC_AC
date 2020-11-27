/*
class Solution {
public:
    typedef pari<int, int> PII;
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 1) return 0;
        int flag = 0;
        vector<PII> f(n);
        for(int i = 0; i + 1 < n; i++) {
            int t = nums[i] - nums[i+1];
            if (t > 0) flag = 1;
            else flag = 0;
            f[i] = make_pair(t, flag);
        }
        vector<int> dp(n-1);
        dp[0] = 1;
        for(int i = 1; i < n-1; i++){
            if(f[i].second != f[i-1].second && f[i]) dp[i] = dp[i-1] + 1;
            else dp[i] = dp[i-1];
        }
        return dp[n-2] + 1
    }
};
*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int n = nums.size();
        if(n <= 2) return n;
        int res = 2;
        for(int i = 1; i + 1 < n; i++) {
            int a = nums[i-1], b = nums[i], c = nums[i+1];
            if(b > a && b > c || b < a && b < c) res ++;
        }
        return res;
    }
};