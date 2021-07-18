class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> hash;
		for(auto &s : strs) {
			string nstr = s;
			sort(nstr.begin(), nstr.end());
			hash[nstr].push_back(s);
		}

		vector<vector<string>> res;
		for(auto [k, v] : hash) {
			res.push_back(v);
		}
		return res;
    }
};