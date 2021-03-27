class Solution {
public:
    int get(int n, int m, int mid) {
        int tot = 0;
        for(int i = 1; i <= m; i++) {
            tot += min(n, mid / i);
        }
        return tot;
    }
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = n * m;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(k <= get(n, m, mid)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};