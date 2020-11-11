class Solution {
public:
    typedef long long LL;
    int m;
    vector<int> tr;
    vector<LL> numbers;

    int get(LL x) {
        return lower_bound(numbers.begin(), numbers.end(), x) - numbers.begin() + 1;
    }

    int lowbit(int x) {
        return x & -x;
    }

    void add(int x, int v) {
        for (int i = x; i <= m; i += lowbit(i)) tr[i] += v;
    }

    int query(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i)) res += tr[i];
        return res;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<LL> s(n + 1);
        numbers.push_back(0);
        for (int i = 1; i <= n; i ++ ) {
            s[i] = s[i - 1] + nums[i - 1];
            numbers.push_back(s[i]);
            numbers.push_back(s[i] - lower);
            numbers.push_back(s[i] - upper - 1);
        }
        sort(numbers.begin(), numbers.end());
        numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
        m = numbers.size();
        tr.resize(m + 1);

        int res = 0;
        add(get(0), 1);
        for (int i = 1; i <= n; i ++ ) {
            res += query(get(s[i] - lower)) - query(get(s[i] - upper - 1));
            add(get(s[i]), 1);
        }
        return res;
    }
};