typedef long long LL;
const int MOD = 1e9 + 7;

class Solution {
public:
	int cnt[310];

	LL C(int a, int b) {
		LL res = 1;
		for(int i = a, j = 1; j <= b; i--, j++) {
			res = res * i / j;
		}
		return res % MOD;
	}

	int calc(int a, int b, int c) {
		if(a == b && b == c) return C(cnt[a], 3);
		if(a == b) return C(cnt[a], 2) * cnt[c] % MOD;
		if(b == c) return cnt[a] * C(cnt[b], 2) % MOD;
		return (LL)cnt[a] * cnt[b] * cnt[c] % MOD;
	}

    int threeSumMulti(vector<int>& arr, int target) {
		for(auto x : arr) cnt[x]++;
		int res = 0;
		for(int i = 0; i <= target; i++) {
			for(int j = i; j <= target - i - j; j++) 
				res = (res + calc(i, j, target - i - j)) % MOD;
		}
		return res;
    }
};