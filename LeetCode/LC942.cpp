class Solution {
public:
    vector<int> diStringMatch(string s) {
		int n = s.size();
		int l = 0, r = n;
		vector<int> res;
		for(auto c : s) {
			if(c == 'I') res.push_back(l++);
			else res.push_back(r--);
		}
		res.push_back(l);
		return res;
    }
};