class Solution {
public:
    string nearestPalindromic(string n) {
        typedef long long LL;
        int len = n.size();
        set<LL> S;
        S.insert((LL)pow(10, len-1)-1);
        S.insert((LL)pow(10, len)+1);
        LL m = stoll(n.substr(0, (len+1) / 2));
        for(LL i = m - 1; i <= m + 1; i++) {
            string a = to_string(i), b = a;
            reverse(b.begin(), b.end());
            if(len % 2) S.insert(stoll(a + b.substr(1)));
            else S.insert(stoll(a + b));
        }
        LL k = stoll(n);
        S.erase(k);
        LL res = 2e18;
        for(auto x : S) {
            if(abs(x - k) < abs(res - k)) res = x;
        }
        return to_string(res);
    }
};