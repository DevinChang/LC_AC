class Solution {
public:
    string getPermutation(int n, int k) {
		string res;
		vector<bool> st(n);
		for(int i = 0; i < n; i++) {
			int fact = 1;
			for(int j = 1; j <= n - i - 1; j++) fact *= j;
			for(int j = 0; j < n; j++) {
				if(!st[j]) {
					if(fact < k) k -= fact;
					else {
						res += to_string(j+1);
						st[j] = true;
						break;
					}
				}
			}
		}
		return res;
    }
};