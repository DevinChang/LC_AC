class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = -1e5;
        for(int i = 0, j = 0, sum = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(i - j + 1 > k) sum -= nums[j++];
            if(i >= k-1) res = max(res, sum / (double)k);
        }
        return res;
    }
};