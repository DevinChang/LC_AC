class Solution {
public:
    bool check(string a, string b) {
        int i = 0, j = 0;
        while(i < a.size() && j < b.size()) {
            if(a[i] == b[j]) i++;
            j++;
        }
        return i == a.size();
    }
    string findLongestWord(string s, vector<string>& d) {
        string res;
        for(auto str : d) {
            if(check(str, s)) {
                if(res.empty() || res.size() < str.size() || res.size() == str.size() && res > str) res = str;
            }
        }
        return res;
    }
};