


int minSubArrayLen(int s, vector<int>& nums) {
    int res = INT_MAX;
    int n = nums.size();
    int sum = 0;
    for(int i = 0, j = 0; i < n; i++) {
        sum += nums[i];
        while(sum - nums[j] >= s) {
            sum -= nums[j];
            j++;
        }
        if(sum >= s) res = min(res, i - j + 1);
    }
    if(res == INT_MAX) return 0;
    return res;
}