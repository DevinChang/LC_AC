class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int n = A.size(), ones = 0;
        for (int i = 0; i < n; i++)
            if (A[i] == 1)
                ones++;

        if (ones % 3 != 0)
            return {-1, -1};

        if (ones == 0)
            return {0, 2};

        ones /= 3;

        int s[3], t[3];
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] == 1) {
                cnt++;
                if (ones == 1)
                    s[cnt / ones - 1] = i;
                if (cnt % ones == 1)
                    s[cnt / ones] = i;

                if (cnt % ones == 0)
                    t[cnt / ones - 1] = i;
            }
        }


        int len = t[0] - s[0] + 1;
        if (t[1] - s[1] + 1!= len || t[2] - s[2] + 1!= len)
            return {-1, -1};

        for (int i = 0; i < len; i++) {
            int x = A[i + s[0]];
            if (x != A[i + s[1]] || x != A[i + s[2]])
                return {-1, -1};
        }

        int last_zeros = n - t[2] - 1;

        if (s[2] - t[1] - 1 < last_zeros || s[1] - t[0] - 1 < last_zeros)
            return {-1, -1};

        return {t[0] + last_zeros, t[1] + last_zeros + 1};
    }
};