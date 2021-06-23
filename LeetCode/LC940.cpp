class Solution {
public:
    int distinctSubseqII(string s) {
		const int MOD = 1e9 + 7;
		int f[26] = {};
		for(auto c : s) {
			int x = c - 'a', s = 1;
			for(int i = 0; i < 26; i++) 
				s = (s + f[i]) % MOD;
			f[x] = s;
		}
		int res = 0;
		for(int x : f) res = (res + x) % MOD;
		return res;
    }
};