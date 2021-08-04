class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		int n = mat.size();
		vector<int> res;
		if(n < 1) return res;
		int m = mat[0].size();
		vector<pair<int,int>> arr;
		for(int i = 0; i < n; i++) {
			pair<int,int> tmp;
			for(int j = 0; j < m; j++) {
				if(mat[i][j] == 1) {
					tmp.first++;
				}
			}
			tmp.second = i;
			arr.push_back(tmp);
		}
		sort(arr.begin(), arr.end());
		for(int i = 0; i < k; i++) {
			res.push_back(arr[i].second);
		}
		return res;
    }
};