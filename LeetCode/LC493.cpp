class Solution {
public:
    #define LL long long
    vector<int> f;
    int m;

    void update(int x, int y) {
        for (; x <= m; x += x & -x)
            f[x] += y;
    }

    int query(int x) {
        int tot = 0;
        for (; x; x -= x & -x)
            tot += f[x];
        return tot;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<LL> b(2 * n);

        for (int i = 0; i < n; i++) {
            b[i] = nums[i];
            b[i + n] = (LL)(nums[i]) * 2;
        }
        sort(b.begin(), b.end());

        m = unique(b.begin(), b.end()) - b.begin();
        b.resize(m);

        f = vector<int>(m + 1, 0);

        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            int x = lower_bound(b.begin(), b.end(), nums[i]) - b.begin() + 1;
            ans += query(x - 1);
            int y = lower_bound(b.begin(), b.end(), (LL)(nums[i]) * 2) - b.begin() + 1;
            update(y, 1);
        }

        return ans;
    }
};
