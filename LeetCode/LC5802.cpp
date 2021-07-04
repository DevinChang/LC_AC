class Solution {
public:
	typedef long long LL;
	const int MOD = 1e9 + 7;
	
	LL qmi(LL a, LL b) {
		LL res = 1 % MOD;
		while(b) {
			if(b & 1) res = res * a % MOD;
			a = a * (LL)a % MOD;
			b >>= 1;
		}
		return res;
	}

    int countGoodNumbers(long long n) {
		return qmi(5, (n+1) / 2) * qmi(4, n / 2) % MOD;
    }
};