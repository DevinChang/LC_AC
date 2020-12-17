class Solution {
public:
    int strongPasswordChecker(string s) {
        int a = 0, b = 0, c = 0, n = s.size(), k = 0;
        for (auto x: s) {
            if (x >= '0' && x <= '9') a = 1;
            else if (x >= 'a' && x <= 'z') b = 1;
            else if (x >= 'A' && x <= 'Z') c = 1;
        }
        k = a + b + c;
        if (n < 6) return max(6 - n, 3 - k);
        else {
            int p = 0, del = n - 20, res = del;
            int d[3] = {0};
            for (int i = 0; i < s.size(); i ++ ) {
                int j = i;
                while (j < s.size() && s[j] == s[i]) j ++ ;
                int s = j - i;
                i = j - 1;
                p += s / 3;
                if (s >= 3) d[s % 3] ++ ;
            }
            if (n <= 20) return max(p, 3 - k);
            if (d[0] && del > 0) {
                int t = min(d[0], del);
                del -= t;
                p -= t;
            }
            if (d[1] && del > 0) {
                int t = min(d[1] * 2, del);
                del -= t;
                p -= t / 2;
            }
            if (p && del > 0) {
                int t = min(p * 3, del);
                p -= t / 3;
            }
            return res + max(p, 3 - k);
        }
    }
};
