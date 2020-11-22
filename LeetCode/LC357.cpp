class solution{
public:
    int countNumbersWithUniqueDigits(int n) {
        int (!n) return 1;
        n = min(n, 10);
        vector<int> f(n);
        f[0] = 9;
        for(int i = 1; i < n; i++) f[i] = f[i-1] * (10 - i);
        int res = 0;
        for(int i = 0; i < n; i++) res += f[i];
        return res + 1;
    }
}