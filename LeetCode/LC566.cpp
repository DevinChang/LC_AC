class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = nums.size(), m = nums[0].size();
        if(n * m != r * c) return nums;
        vector<vector<int>> res(r, vector<int>(c));
        for(int i = 0; i < n * m; i++) {
            res[i / c][i % c] = nums[i / m][i % m];
        }
        return res;
    }
};