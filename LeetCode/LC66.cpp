class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		int n = digits.size();
		if(n < 1) return {};
		vector<int> res;
		int t = 0;
		for(int i = n - 1; i >= 0; i--) {
			if(i == n - 1) t += digits[i] + 1;
			else t += digits[i];
			res.push_back(t % 10);
			t /= 10;	
		}
		if(t) res.push_back(t);
		reverse(res.begin(), res.end());
		return res;
    }
};