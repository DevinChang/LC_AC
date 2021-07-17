class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		string res;
		if(strs.empty()) return res;
		int i = 0, n = strs[0].size();
		while(i < n) {
			char c = strs[0][i];
			for(auto str : strs) {
				if(str.size() < i || str[i] != c) return res;
			}
			res += c;
			i++;
		}
		return res;
    }
};