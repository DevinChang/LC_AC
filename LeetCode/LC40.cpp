class Solution {
public:
	vector<vector<int>> res;
	vector<int> path;

	void dfs(vector<int>& c, int t, int u) {
		if(t == 0) {
			res.push_back(path);
			return;
		}
		if(u == c.size()) return;

		int k = u+1;
		while(k < c.size() && c[u] == c[k]) k++;
		int cnt = k - u;
		for(int i = 0; i * c[u] <= t && i <= cnt; i++) {
			dfs(c, t - i * c[u], k);
			path.push_back(c[u]);
		}
		for(int i = 0; i * c[u] <= t && i <= cnt; i++) path.pop_back();
	}

    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
		sort(c.begin(), c.end());
		dfs(c, t, 0);
		return res;
    }
};