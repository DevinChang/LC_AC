class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x : nums) sum += x;
        if (sum % 2) return false;
        sum /= 2;
        vector<int> f(sum + 1);
        f[0] = 1;
        for(auto x : nums) {
            for(int j = sum; j >= x; j--) f[j] |= f[j-x];
        }
        return f[sum];
    }
};