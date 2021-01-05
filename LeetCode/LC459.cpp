class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        s = ' ' + s;
        vector<int> next(n+1);
        for(int i = 2, j = 0; i <= n; i++){
            while(j && s[i] != s[j+1]) j = next[j];
            if(s[i] == s[j+1]) j++;
            next[i] = j;
        }
        int t = n - next[n];
        return t < n && n % t == 0;
    }
};