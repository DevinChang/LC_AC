
class NumArray {
public:
    vector<int> sums;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums = vector<int> (n+1, 0);
        for(int i = 1; i <= n; i++) sums[i] = sums[i-1] + nums[i-1];
    }
    
    int sumRange(int i, int j) {
        return sums[j+1] - sums[i];
    }
};
