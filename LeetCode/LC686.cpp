class Solution {
public:
    int repeatedStringMatch(string a, string p) {
        string s;
        while(s.size() < p.size()) s += a;
        s += a;
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;
        vector<int> next(m+1);
        for(int i = 2, j = 0; i <= m; i++) {
            while(j && p[i] != p[j+1]) j = next[j];
            if(p[i] == p[j+1]) j++;
            next[i] = j;
        }
        for(int i = 1, j = 0; i <= n; i++) {
            while(j && s[i] != p[j+1]) j = next[j];
            if(s[i] == p[j+1]) j++;
            if(j == m) return (i + a.size()-1) / a.size();
        }
        return -1;
    }
};