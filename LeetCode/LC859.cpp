class Solution {
public:
    bool buddyStrings(string a, string b) {
        if(a.size() != b.size()) return false;
        if(a == b) {
            unordered_map<char,int> hash;
            for(auto c : a) {
                if(++hash[c] > 1) return true;
            }
            return false;
        }
        vector<int> cnt;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) cnt.push_back(i);
        }
        if(cnt.size() != 2) return false;
        int x = cnt[0], y = cnt[1];
        if(a[y] == b[x] && a[x] == b[y]) return true;
        return false;
    }
};