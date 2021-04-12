class Solution {
public:
    int countPalindromicSubsequences(string S) {
        const int MOD = 1000000007;
        int n = S.length();
        vector<vector<int>> f(n, vector<int>(n, 1));

        for (int i = 0; i < n; i++)
            f[i][i] = 2;

        for (int len = 2; len <= n; len++) {

            deque<int> ch[4];
            for (int i = 0; i < len - 1; i++)
                ch[S[i] - 'a'].push_back(i);

            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                ch[S[j] - 'a'].push_back(j);

                for (int k = 0; k < 4; k++)
                    if (ch[k].size() > 0) {
                        f[i][j]++;
                        int l = ch[k].front();
                        int r = ch[k].back();
                        if (l < r)
                            f[i][j] = (f[i][j] + f[l + 1][r - 1]) % MOD;
                    }

                ch[S[i] - 'a'].pop_front();
            }
        }

        return (f[0][n - 1] + MOD - 1) % MOD;
    }
};