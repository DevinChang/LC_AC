


bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    typedef long long LL;
    multiset<LL> ms;
    // 插入哨兵防止越界
    ms.insert(1e18), ms.insert(-1e18);
    int n = nums.size();
    for (int i = 0, j = 0; i < n; i ++ ) {
        // 窗口大小大于k
        if (i - j > k) ms.erase(ms.find(nums[j ++ ]));
        int x = nums[i];
        auto it = ms.lower_bound(x);
        if (*it - x <= t) return true;
        // 判断小于nums[i]的元素是否符合要
        -- it;
        if (x - *it <= t) return true;
        ms.insert(x);
    }
    return false;
}