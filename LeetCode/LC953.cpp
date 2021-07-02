class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
		unordered_map<char, int> hash;
		for(int i = 0; i < order.size(); i++) hash[order[i]] = i;

		for(int i = 1; i < words.size(); i ++) {
			auto a = words[i-1], b = words[i];
			int x = 0, y = 0;
			while(x < a.size() && y < b.size()){
				if(hash[a[x]] < hash[b[y]]) break;
				if(hash[a[x]] > hash[b[y]]) return false;
				x++, y++;
			}
			if(x < a.size() && y == b.size()) return false;
		}
		return true;
    }
};