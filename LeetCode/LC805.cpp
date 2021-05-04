class Solution {
public:
    vector<int> nums;
    unordered_multiset<int> S;

    void dfs1(int u, int n, int sum) {
        if (u == n) S.insert(sum);
        else {
            dfs1(u + 1, n, sum);
            dfs1(u + 1, n, sum + nums[u]);
        }
    }

    bool dfs2(int u, int n, int sum, int cnt) {
        if (u == n) {
            if (cnt && cnt < n && S.count(-sum)) return true;
            return false;
        } else {
            if (dfs2(u + 1, n, sum, cnt)) return true;
            if (dfs2(u + 1, n, sum + nums[u], cnt + 1)) return true;
            return false;
        }
    }

    bool splitArraySameAverage(vector<int>& _nums) {
        nums = _nums;
        int n = nums.size();
        if (n == 1) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (auto& x: nums) x = x * n - sum;

        int m = n / 2;
        dfs1(m, n, 0);
        int s1 = 0, s2 = accumulate(nums.begin() + m, nums.begin() + n, 0);
        S.erase(S.find(s1));
        if (S.count(0)) return true;
        S.insert(s1), S.erase(S.find(s2));
        if (S.count(-accumulate(nums.begin(), nums.begin() + m, 0))) return true;
        return dfs2(0, m, 0, 0);
    }
};