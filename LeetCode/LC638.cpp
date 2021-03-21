class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size(), m = special.size();
        vector<int> f(270000, INT_MAX);
        f[0] = 0;

        for (int i = n; i < 6; i++) {
            price.push_back(0);
            needs.push_back(0);
        }
        for (int i = 0; i < m; i++) {
            int t = special[i][n];
            special[i][n] = 0;
            for (int j = n + 1; j < 7; j++)
                special[i].push_back(0);
            special[i][6] = t;
        }

        int T = 0;
        // T 表示最终的状态。
        for (int i = 0; i < 6; i++)
            T |= needs[i] << (i * 3);

        for (int S = 1; S <= T; S++) {
            bool check_flag = true;
            for (int i = 0; i < 6; i++) {
                int s = (S >> (i * 3)) & 7;
                // 小 s 就代表大 S 中的某三个二进制位，相当于 i0, i1, ..., i5。
                if (s > needs[i]) {
                    check_flag = false;
                    break;
                }
            }
            if (!check_flag)
                continue;

            for (int i = 0; i < 6; i++) {
                int s = (S >> (i * 3)) & 7;
                if (s > 0)
                    f[S] = min(f[S], f[(S & (~(7 << (i * 3)))) | ((s - 1) << (i * 3))] + price[i]);
            }
            for (int i = 0; i < m; i++) {
                check_flag = true;
                int t = 0;
                for (int j = 0; j < 6; j++) {
                    int s = S >> (j * 3) & 7;
                    if (s < special[i][j]) {
                        check_flag = false;
                        break;
                    }
                    t |= (s - special[i][j]) << (j * 3);
                }
                if (check_flag)
                    f[S] = min(f[S], f[t] + special[i][6]);
            }
        }

        return f[T];
    }
};