const int N = 100010, M = 110;

int s[N][M];

class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size(), m = q.size();
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= 100; j ++ ) {
                int t = 0;
                if (nums[i - 1] == j) t = 1;
                s[i][j] = s[i - 1][j] + t;
            }
        vector<int> res(m);
        for (int i = 0; i < m; i ++ ) {
            int l = q[i][0] + 1, r = q[i][1] + 1;
            int t = M, last = -1;
            for (int j = 1; j <= 100; j ++ )
                if (s[r][j] > s[l - 1][j]) {
                    if (last != -1) t = min(t, j - last);
                    last = j;
                }
            if (t == M) t = -1;
            res[i] = t;
        }
        return res;
    }
};