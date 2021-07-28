class Solution {
public:
    int climbStairs(int n) {
		int a = 1, b = 1;
		while(--n) {
			int c = a + b;
			a = b, b = c;
		}
		return b;
    }
};