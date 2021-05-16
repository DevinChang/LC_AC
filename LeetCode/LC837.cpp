const int N = 20010;
double f[N];

class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (!K) return 1;
        memset(f, 0, sizeof f);
        for (int i = K; i <= N && i < K + W; i ++ ) f[i] = 1;
        f[K - 1] = 0;
        for (int i = 1; i <= W; i ++ ) f[K - 1] += f[K - 1 + i] / (double)W;
        for (int i = K - 2; i >= 0; i -- )
            f[i] = f[i + 1] + (f[i + 1] - f[i + W + 1]) / (double)W;
        return f[0];
    }
};