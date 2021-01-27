class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        if(m == 0) return {};
        const int n = matrix[0].size();
        vector<int> ans(m * n);
        int cnt = 0;
        for(int s = 0; s <= m + n - 2; s++) {
            // 从上到下遍历的对角线
            if(s % 2 == 0) {
                for(int i = min(m-1, s); i >= max(0, s - n + 1); i--) {
                    ans[cnt++] = matrix[i][s-i];
                }
            }
            else {
                for(int i = max(0, s-n+1); i <= min(m-1, s); i++) {
                    ans[cnt++] = matrix[i][s-i];
                }
            }
        }
        return ans;
    }
};