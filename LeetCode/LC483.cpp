class Solution {
public:
    #define LL long long
    string smallestGoodBase(string n) {
        LL N = stoll(n);
        for(int t = log2(N) + 1;  t >= 3; t--) {
            LL k = pow(N, 1.0 / (t-1));
            LL tot = 0;
            for(int i = 0; i < t; i++) tot = tot * k + 1;
            if(tot == N) return to_string(k);
        }
        return to_string(N-1);
    }
};