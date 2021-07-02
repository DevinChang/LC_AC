class Solution {
public:
	vector<int> p, s;

	int find(int x) {
		if(p[x] != x) p[x] = find(p[x]);
		return p[x];
	}

    int largestComponentSize(vector<int>& nums) {
		int n = nums.size();
		for(int i = 0; i < n; i++) {
			p.push_back(i);
			s.push_back(1);
		}

		unordered_map<int, vector<int>> q;
		for(int i = 0; i < n; i++) {
			int x = nums[i];
			for(int j = 1; j * j <= x; j++) {
				if(x % j == 0) {
					if(j > 1) q[j].push_back(i);
					q[x / j].push_back(i);
				}
			}
		}
		int res = 0;
		for(auto [k, v] : q) {
			for(int i = 1; i < v.size(); i++) {
				int a = v[0], b = v[i];
				if(find(a) != find(b)) {
					s[find(a)] += s[find(b)];
					p[find(b)] = find(a);
					res = max(res, s[find(a)]);
				}
			}
		}
		return res;
    }
};