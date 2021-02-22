class Solution {
public:
    int countArrangement(int n) {
        vector<int> f(1 << n);
        f[0] = 1;
        for (int i = 0; i < 1 << n; i ++ ) {
            int k = 0;
            for (int j = 0; j < n; j ++ )
                if (i >> j & 1)
                    k ++ ;
            for (int j = 0; j < n; j ++ )
                if (!(i >> j & 1)) {
                    if ((k + 1) % (j + 1) == 0 || (j + 1) % (k + 1) == 0)
                        f[i | (1 << j)] += f[i];
                }
        }
        return f[(1 << n) - 1];
    }
};
