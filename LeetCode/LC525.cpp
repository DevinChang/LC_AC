class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_map<int,int> hash;
        hash[0] = 0;
        int x = 0;
        for(int i = 1; i <= n; i++) {
            x += (nums[i-1] == 1 ? 1 : -1);
            if(hash.count(x)) ans = max(ans, i - hash[x]);
            else hash[x] = i;
        }
        return ans;
    }
};