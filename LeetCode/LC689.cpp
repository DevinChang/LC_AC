class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> nums, int k) {
        int n = nums.size();
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + nums[i - 1];
        vector<vector<int>> f(n + 2, vector<int>(4));

        int x = n + 1, y = 3;
        for (int i = n - k + 1; i; i -- ) {
            for (int j = 1; j <= 3; j ++ )
                f[i][j] = max(f[i + 1][j], f[i + k][j - 1] + s[i + k - 1] - s[i - 1]);
            if (f[x][3] <= f[i][3]) x = i;
        }

        vector<int> res;
        while (y) {
            while (f[x][y] != f[x + k][y - 1] + s[x + k - 1] - s[x - 1]) x ++ ;
            res.push_back(x - 1);
            x += k, y -- ;
        }
        return res;
    }
};