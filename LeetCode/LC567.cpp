class Solution {
public:
    unordered_map<char, int> h1, h2;

    bool check(char c) {
        if(h1.count(c) && h1[c] == h2[c]) return true;
        return false;
    }

    bool checkInclusion(string s1, string s2) {
        for(auto c : s1) h1[c]++;        
        for(int i = 0, j = 0, cnt = 0; i < s2.size(); i++) {
            if(check(s2[i])) cnt--;
            h2[s2[i]]++;
            if(check(s2[i])) cnt++;
            if(i - j >= s1.size()) {
                if(check(s2[j])) cnt--;
                h2[s2[j]]--;
                if(check(s2[j])) cnt++;
                j++;
            }
            if(cnt == h1.size()) return true;
        }
        return false;
    }
};