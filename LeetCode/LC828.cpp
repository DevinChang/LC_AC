class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size(), MOD = 1e9 + 7;
        vector<int> l(n, -1), r(n, -1);
        vector<int> p(26, -1);
        for(int i = 0; i < n; i++) {
            l[i] = p[s[i] - 'A'];
            p[s[i] - 'A'] = i;
        }
        p = vector<int>(26, n);
        for(int i = n-1; i >= 0; i--) {
            r[i] = p[s[i]-'A'];
            p[s[i]-'A'] = i;
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            res = (res + (long long)(i - l[i]) * (r[i] - i)) % MOD;
        }
        return res;
    }
};