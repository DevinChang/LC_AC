typedef long long LL;

class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

    LL get(LL mid, int a, int b) {
        // 求[1,N]中有多少能整除a或b的值等于:
        // N/a + N /b - N / [a,b]     [a,b]->a,b的最小公倍数
        // 两个数的乘积等于最小公倍数和最大公约数的乘积
        return mid / a + mid / b - mid / (a * b / gcd(a, b));
    }

    int nthMagicalNumber(int n, int a, int b) {
        const int MOD = 1e9 + 7;
        LL l = 1, r = 4e13;
        while (l < r) {
            LL mid = l + r >> 1;
            if (get(mid, a, b) >= n) r = mid;
            else l = mid + 1;
        }
        return r % MOD;
    }
};

