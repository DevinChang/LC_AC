class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int>& nums, int start) {
        if(path.size() >= 2) res.push_back(path);
        if(start == nums.size()) return;
        unordered_set<int> S;
        for(int i = start; i < nums.size(); i++) {
            if(path.empty() || nums[i] >= path.back()) {
                if(S.count(nums[i])) continue;
                S.insert(nums[i]);
                path.push_back(nums[i]);
                dfs(nums, i + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
};