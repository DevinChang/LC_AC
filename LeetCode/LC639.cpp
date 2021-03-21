class Solution {
public:
    int numDecodings(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        vector<long long> f(n+1);
        f[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 26; j++) {
                char a = s[i-1];
                if(j <= 9) {
                    if(a == '*' || a == j + '0') f[i] += f[i-1];
                } else if (i >= 2) {
                    char b = s[i-2];
                    int y = j / 10, x = j % 10;
                    if((b == y + '0' || b == '*' && y) && (a == x + '0' || a == '*' && x)) f[i] += f[i-2];
                }
                f[i] %= MOD;
            }
        }
        return f[n];
    }
};