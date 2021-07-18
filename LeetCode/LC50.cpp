class Solution {
public:
	typedef long long LL;
	
    double myPow(double x, int n) {
		double res = 1, p = x;
		LL t = abs((LL)(n));
		for(; t; t >>= 1) {
			if(t & 1) res = res * p;
			p = p * p;	
		}
		return n > 0 ? res : 1 / res;
    }
};