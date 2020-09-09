
int maximumGap(vector<int>& nums) {
    struct Range {
        int min, max;
        bool used;
        Range() : min(INT_MAX), max(INT_MIN), used(false){}
    };
    int n = nums.size();
    int Min = INT_MAX, Max = INT_MIN;
    for (auto x: nums) {
        Min = min(Min, x);
        Max = max(Max, x);
    }
    if (n < 2 || Min == Max) return 0;
    vector<Range> r(n - 1);
    int len = (Max - Min + n - 2) / (n - 1);
    for (auto x: nums) {
        if (x == Min) continue;
        int k = (x - Min - 1) / len;
        r[k].used = true;
        r[k].min = min(r[k].min, x);
        r[k].max = max(r[k].max, x);
    }
    int res = 0;
    for (int i = 0, last = Min; i < n - 1; i ++ )
        if (r[i].used) {
            res = max(res, r[i].min - last);
            last = r[i].max;
        }
    return res;
}

