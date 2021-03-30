class Solution {
public:
    vector<double> get(vector<double> nums, int i, int j, double x) {
        vector<double> res;
        for(int k = 0; k < nums.size(); k++) {
            if(k != i && k != j) res.push_back(nums[k]);
        }
        res.push_back(x);
        return res;
    }
    bool dfs(vector<double> nums) {
        int n = nums.size();
        if(n == 1) return fabs(nums[0] - 24) < 1e-8;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                if(i != j) {
                    double a = nums[i], b = nums[j];
                    if(dfs(get(nums, i, j, a + b))) return true;
                    if(dfs(get(nums, i, j, a - b))) return true;
                    if(dfs(get(nums, i, j, a * b))) return true;
                    if(b && dfs(get(nums, i, j, a / b))) return true;
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& nums) {
        vector<double> a(nums.begin(), nums.end());
        return dfs(a);
    }
};