class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for(int len = 0; len < s.size(); len++) {
            // 奇数情况
            for(int j = len, k = len; j >= 0 && k < s.size(); j--, k++) {
                if(s[j] != s[k]) break;
                res++;
            }
            // 偶数情况
            for(int j = len, k = len+1; j >= 0 && k < s.size(); j--,k++) {
                if(s[j] != s[k]) break;
                res++;
            }
        }
        return res;
    }
};