class Solution {
public:
	bool work(string& stamp, string& target, int k) {
		if(target.substr(k, stamp.size()) == string(stamp.size(), '?')) 
			return false;
		for(int i = 0; i < stamp.size(); i++) {
			if(target[k+i] != '?' && stamp[i] != target[k+i])
				return false;
		}
		for(int i = 0; i < stamp.size(); i++)
			target[k+i] = '?';
		return true;
	}

    vector<int> movesToStamp(string stamp, string target) {
		vector<int> res;
		while(true) {
			bool flag = true;
			for(int i = 0; i + stamp.size() <= target.size(); i++) {
				if(work(stamp, target, i)) {
					res.push_back(i);
					flag = false;
				}
			}
			if (flag) break;
		}
		if(target != string(target.size(), '?')) return {};
		reverse(res.begin(), res.end());
		return res;
    }
};