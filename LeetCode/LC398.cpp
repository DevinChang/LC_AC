class Solution {
public:
    unordered_map<int, vector<int>> hash;
    Solution(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            hash[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        return hash[target][rand() % hash[target].size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */