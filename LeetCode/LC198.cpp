//
// Created by devinchang on 2019/12/30.
//
#include "util.h"


int rob(vector<int>& nums){
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



int main(){
    string line;
    while(getline(cin, line)){
        vector<int> nums = stringToIntegerVector(line);
        int ret = rob(nums);
        cout << to_string(ret) << endl;
    }

    return 0;
}

