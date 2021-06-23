class Solution {
    vector<vector<int>> res;
    vector<int> path, nums;
    vector<bool> state;
    int n;
public:
    void dfs(int u) {
        if(u == n) {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(state[i] == false) {
                path[u] = nums[i];
                state[i] = true;
                dfs(u+1);
                state[i] = false;
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& _nums) {
        nums = _nums;
        n = nums.size();
        path = vector<int>(n);
        state = vector<bool>(n);
        dfs(0);
        return res;
    }
};