class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(), s.end());
        for(int i = 0; i < n; i++) {
            int j = i;
            while(j < n && s[j] != ' ') j++;
            reverse(s.begin() + i, s.begin() + j);
            i = j;
        }
        return s;
    }
};