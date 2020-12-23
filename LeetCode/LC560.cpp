class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> S(n+1);
        for(int i = 1; i <= n; i++) {
            S[i] = S[i-1] + nums[i-1];
        }
        int res = 0;
        unordered_map<int,int> hash;
        hash[0] = 1;
        for(int i = 1; i <= n; i++) {
            res += hash[S[i] - k];
            hash[S[i]]++;
        }
        return res;
    }
};