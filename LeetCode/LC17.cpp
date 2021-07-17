class Solution {
public:
	vector<string> res;
	string path;
	string phones[10] = {
		"", "", "abc", "def",
		"ghi", "jkl", "mno",
		"pqrs", "tuv", "wxyz"
	};

	void dfs(string digits, int u) {
		if(u == digits.size()) {
			res.push_back(path);
			return;
		}
		for(auto &c : phones[digits[u]-'0']) {
			path += c;
			dfs(digits, u+1);
			path.pop_back();
		}
	}

    vector<string> letterCombinations(string digits) {
		if(digits.empty()) return {};
		dfs(digits, 0);
		return res;
    }
};