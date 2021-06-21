class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
		int n = matrix.size(), m = matrix[0].size();
		vector<vector<int>> f(n, vector<int>(m, INT_MAX));

		for(int i = 0; i < m; i++) f[0][i] = matrix[0][i];

		for(int i = 1; i < n; i++) {
			for(int j = 0; j < m; j++) {
				for(int k = max(0, j - 1); k <= min(m-1, j+1); k++) {
					f[i][j] = min(f[i][j], f[i-1][k] + matrix[i][j]);
				}
			}
		}

		int res = INT_MAX;
		for(int i = 0; i < m; i++) res = min(res, f[n-1][i]);
		
		return res;
    }
};