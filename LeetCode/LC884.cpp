class Solution {
public:
    void work(string &s, unordered_map<string, int>& cnt) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') continue;
            int j = i;
            while(j < s.size() && s[j] != ' ') j++;
            cnt[s.substr(i, j - i)]++;
            i = j;
        }
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> c1, c2;
        work(s1, c1);
        work(s2, c2);
        vector<string> res;
        for(auto [k, v] : c1) {
            if(v == 1 && !c2.count(k)) res.push_back(k);
        }
        for(auto [k, v] : c2) {
            if(v == 1 && !c1.count(k)) res.push_back(k);
        }
        return res;
    }
};