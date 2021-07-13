class Solution {
public:
	vector<vector<int>> res;
	vector<int> path;

	void dfs(vector<int> &c, int u, int target) {
		if(target == 0) {
			res.push_back(path);
			return;
		}
		if(u == c.size()) return;
		int k = u + 1;
		while(k < c.size() && c[k] == c[u]) k++;
		int cnt = k - u;
		for(int i = 0; i * c[u] <= target && i <= cnt; i++) {
			dfs(c, k, target - i * c[u]);
			path.push_back(c[u]);
		}
		for(int i = 0; i * c[u] <= target && i <= cnt; i++) path.pop_back();
	}

    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
		sort(c.begin(), c.end());
		dfs(c, 0, target);
		return res;		
    }
};