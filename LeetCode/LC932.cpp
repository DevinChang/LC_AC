class Solution {
public:
    vector<int> beautifulArray(int n) {
		if(n == 1) return {1};
		auto left = beautifulArray((n+1) / 2);
		auto right = beautifulArray(n / 2);

		vector<int> res;
		for(auto x : left) res.push_back(x * 2 - 1);
		for(auto y : right) res.push_back(y * 2);

		return res;
    }
};