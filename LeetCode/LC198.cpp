//
// Created by devinchang on 2019/12/30.
//
#include "util.h"


int rob_origin(vector<int>& nums){
    /*
    int len = nums.size();
    if(len < 1)
        return 0;
    if(len < 2)
        return nums[0];
    if(len < 3)
        return nums[0] > nums[1] ? nums[0] : nums[1];
    vector<int> dp(len, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);
    for(int i = 2; i < len; i++){
        dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
    }
    return dp[len-1];
    */
    int len = nums.size();
    if(len < 1){
        return 0;
    }
    vector<int> dp(len+1, 0);
    dp[1] = nums[0];
    for(int i = 2; i <= len; i++){
        dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);
    }
    return dp[len];
}


int rob(vector<int> &nums) {
    int n = nums.size();
    if (n < 1) return 0;
    vector<int> dp(n+1, 0);
    dp[1] = nums[0];
    for(int i = 2; i <= n; i++) {
        dp[i] = max(dp[i-2] + nums[i-1], dp[i-1]);
    }
    return dp[n];
}

int rob(vector<int> &nums) {
    int n = nums.size();
    int g = 0, f = nums[0];
    for(int i = 1; i < n; i++) {
        int last_f = f, last_g = g;
        f = g + nums[i];
        g = max(last_f, last_g);
    }
    return max(f, g);
}


int main(){
    string line;
    while(getline(cin, line)){
        vector<int> nums = stringToIntegerVector(line);
        int ret = rob(nums);
        cout << to_string(ret) << endl;
    }

    return 0;
}

