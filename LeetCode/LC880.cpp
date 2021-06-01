class Solution {
public:
    #define LL long long
    string decodeAtIndex(string S, int K) {
        int n = S.length();
        LL len = 0;
        for (auto &c : S) {
            if (isalpha(c))
                len++;
            else
                len *= c - '0';
        }

        for (int i = n - 1; i >= 0; i--) {
            if (isalpha(S[i])) {
                if (K == len)
                    return S.substr(i, 1);
                len--;
            }
            else {
                len /= S[i] - '0';
                if (K % len == 0) {
                    for (int j = i - 1; j >= 0; j--)
                        if (isalpha(S[j]))
                            return S.substr(j, 1);
                }
                K %= len;
            }
        }

        return "";
    }
};
