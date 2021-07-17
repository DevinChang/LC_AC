class Solution {
public:
    bool isPalindrome(int x) {
		if(x < 0) return false;
		int r = 0, k = x;
		while(k) {
			if(r > (INT_MAX - k % 10) / 10) return false;
			r = r * 10 + k % 10;
			k /= 10;
		}
		return r == x;
    }
};