class Solution {
public:

    #define LL long long

    int calc(int prefix, int n) {
        int tot = 0;
        LL t = prefix, k = 1;
        while(t * 10 <= n) {
            tot += k;
            k *= 10;
            t *= 10;
        }
        if(t <= n) {
            if(n - t < k) {
                tot += n - t + 1;
            } else {
                tot += k;
            }
        }
        return tot;
    }

    int findKthNumber(int n, int k) {
        int prefix = 1;
        while(k > 1) {
            int sz = calc(prefix, n);
            cout << "prefix= " << prefix << "\n" << "n= " << n << endl;
            cout << "k= " << k << "\n" << "sz= " << sz << endl;
            if(k > sz) {
                k -= sz;
                prefix++;
            } else {
                k--;
                prefix = prefix * 10;
            }
        }
        return prefix;
    }
};