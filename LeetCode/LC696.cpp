class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0;
        int last = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            int j = i + 1; 
            while(j < n && s[i] == s[j]) j++;
            int cur = j - i;
            i = j-1;
            res += min(last, cur);
            last = cur;
        }
        return res;
    }
};