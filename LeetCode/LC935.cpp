class Solution {
public:
    int knightDialer(int n) {
		vector<vector<int>> f(n, vector<int>(10, 0));
		for(int i = 0; i < 10; i++) f[0][i] = 1;
		vector<int> tr[10] = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {3, 9, 0},
            {},
            {1, 7, 0},
            {2, 6},
            {1, 3},
            {2, 4},
        };
		const int MOD = 1e9 + 7;
		for(int i = 0; i < n - 1; i++) {
			for(int j = 0; j < 10; j++) {
				for(int x : tr[j])
					f[i+1][x] = (f[i+1][x] + f[i][j]) % MOD;
			}
		}
		int res = 0;
		for(int i = 0; i < 10; i++) res = (res + f[n-1][i]) % MOD;

		return res;
    }
};