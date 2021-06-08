typedef long long LL;

class Solution {
public:
    bool check(string s, string left, string right) {
        auto x = stoll(s), l = stoll(left), r = stoll(right);
        if (x > INT_MAX) return false;

        x *= x;
        if (x < l || x > r) return false;

        s = to_string(x);
        for (int i = 0, j = s.size() - 1; i < j; i ++, j -- )
            if (s[i] != s[j])
                return false;

        return true;
    }

    int superpalindromesInRange(string left, string right) {
        int res = 0;
        for (int i = 1; i <= 20001; i ++ ) {
            auto a = to_string(i);
            string b(a.rbegin(), a.rend());
            if (check(a + b, left, right)) res ++ ;
            if (check(a + b.substr(1), left, right)) res ++ ;
        }
        return res;
    }
};