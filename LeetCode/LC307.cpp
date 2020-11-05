
class NumArray {
public:
    int n;
    vector<int> tr, nums;

    int lowbit(int x) {
        return x & -x;
    }

    int query(int x) {
        int ret = 0;
        for (int i = x; i; i -= lowbit(i)) ret += tr[i];
        return ret;
    }

    void add(int x, int v) {
        for (int i = x; i <= n; i += lowbit(i)) tr[i] += v;
    }

    NumArray(vector<int>& _nums) {
        nums = _nums;
        n = nums.size();
        tr.resize(n + 1);

        for (int i = 1; i <= n; i ++ ) {
            tr[i] = nums[i - 1];
            for (int j = i - 1; j > i - lowbit(i); j -= lowbit(j))
                tr[i] += tr[j];
        }
    }

    void update(int i, int val) {
        add(i + 1, val - nums[i]);
        nums[i] = val;
    }

    int sumRange(int i, int j) {
        return query(j + 1) - query(i);
    }
};