class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(auto n : nums) hash[n]++;
        int res = 0;
        for(auto [c, n] : hash) {
            if(hash.count(c+1)) res = max(res, hash[c] + hash[c+1]);
        }
        return res;
    }
};