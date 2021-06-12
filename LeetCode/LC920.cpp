typedef long long LL;
const int N = 210, MOD = 1e9 + 7;

int f[N][N];

class Solution {
public:
    int numMusicPlaylists(int n, int m, int k) {
		f[0][0] = 1;
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n && j <= i; j++) {
				f[i][j] = ((LL)f[i-1][j-1] * (n - j + 1) + 
						(LL)f[i-1][j] * max(j-k, 0)) % MOD;
			}
		}
		return f[m][n];
    }
};