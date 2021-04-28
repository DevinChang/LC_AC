typedef long long LL;

class Solution {
public:
    int preimageSizeFZF(int k) {
        return calc(k) - calc(k - 1);
    }

    LL f(LL x) {
        LL res = 0;
        while (x) res += x / 5, x /= 5;
        return res;
    }

    LL calc(int k) {
        LL l = -1, r = 1e18;
        while (l < r) {
            LL mid = l + r + 1 >> 1;
            if (f(mid) <= k) l = mid;
            else r = mid - 1;
        }
        return r;
    }
};