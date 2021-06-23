class Solution {
public:
    vector<vector<int>> res;
    vector<int> path, nums;
    vector<bool> state;
    int n;

    void dfs(int u) {
        if(u == n) {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(state[i] == false) {
                if(i > 0 && nums[i-1] == nums[i] && state[i-1] == false) continue;
                path[u] = nums[i];
                state[i] = true;
                dfs(u+1);
                state[i] = false;
            }
        }
        return;
    }

    vector<vector<int>> permuteUnique(vector<int>& _nums) {
        nums = _nums;
        n = nums.size();
        sort(nums.begin(), nums.end());

        state = vector<bool>(n);
        path = vector<int>(n);
        
        dfs(0);

        return res;
    }
};