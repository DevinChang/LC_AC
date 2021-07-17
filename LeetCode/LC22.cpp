class Solution {
public:
	vector<string> res;

	void dfs(int n, int ln, int rn, string path) {
		if(ln == n && rn == n) res.push_back(path);
		else {
			if(ln < n) dfs(n, ln+1, rn, path+'(');
			if(rn < n && rn < ln) dfs(n, ln, rn+1, path+')');
		}
	}

    vector<string> generateParenthesis(int n) {
		dfs(n, 0, 0, "");	
		return res;
    }
};