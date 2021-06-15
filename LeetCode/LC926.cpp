class Solution {
public:
    int minFlipsMonoIncr(string str) {
        int n = str.size();
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i ++ )
            s[i] = s[i - 1] + str[i - 1] - '0';

        int res = n - s[n];
        for (int i = 1; i <= n; i ++ )
            res = min(res, s[i] + n - i - (s[n] - s[i]));
        return res;
    }
};