class Solution {
public:
	vector<vector<int>> res;
	vector<int> path;

	void dfs(vector<int>& c, int u, int target) {
		if(target == 0) {
			res.push_back(path);
			return;
		}
		if(u == c.size()) return;

		for(int i = 0; i * c[u] <= target; i++) {
			dfs(c, u+1, target - i * c[u]);
			path.push_back(c[u]);
		}
		for(int i = 0; i * c[u] <= target; i++) path.pop_back();
		return;
	}

    vector<vector<int>> combinationSum(vector<int>& c, int target) {
		dfs(c, 0, target);
		return res;
    }
};