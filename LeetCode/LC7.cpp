class Solution {
public:
    int reverse(int x) {
		int r;
		while(x) {
			if(r > 0 && r > (INT_MAX - x % 10) / 10 ) return 0;
			if(r < 0 && r < (INT_MIN - x % 10) / 10) return 0;
			r = r * 10 + x % 10;
			x /= 10;
		}	
		return r;
    }
};