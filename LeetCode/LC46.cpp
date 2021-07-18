class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> state;

    void dfs(vector<int>& nums, int u) {
        if(u == nums.size()) {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(state[i] == false) {
                path[u] = nums[i];
                state[i] = true;
                dfs(nums, u+1);
                state[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        state = vector<bool>(n);
        path = vector<int>(n);
        dfs(nums, 0);
        return res;
    }
};