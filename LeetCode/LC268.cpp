

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int res = n * (n + 1) / 2;
    int sum = 0;
    for(auto i : nums) sum += i;
    return res - sum;
}