class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
	    unordered_map<char, int> max_count;
		for(auto &w : words2) {
			unordered_map<char,int> cnt;
			for(auto c : w) cnt[c]++;
			for(auto [k,v] : cnt)
				max_count[k] = max(max_count[k], v);
		}
		vector<string> res;
		for(auto &w : words1) {
			unordered_map<char, int> cnt;
			for(auto c : w) cnt[c]++;
			bool flag = true;
			for(auto [k,v] : max_count) {
				if(cnt[k] < v) {
					flag = false;
					break;
				}
			}
			if(flag) res.push_back(w);
		}
		return res;
    }
};