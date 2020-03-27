//
// Created by devinchang on 2019/12/30.
//
#include "util.h"


int myrob(vector<int>& nums){
    int len = nums.size();
    if(len == 1)
        return nums[0];
    vector<int> dp(len+1, 0);
    dp[1] = nums[0];
    for(int i = 2; i <= len; i++){
        dp[i] = max(dp[i-2] + nums[i-1], dp[i-1]);
    }
    return dp[len];
}


int rob(vector<int> &nums){
    if(nums.size() < 1)
        return 0;
    if(nums.size() == 1)
        return nums[0];
    vector<int> nums1(nums.begin(), nums.end()-1);
    vector<int> nums2(nums.begin()+1, nums.end());
    int ret1 = myrob(nums1);
    int ret2 = myrob(nums2);
    return max(ret1, ret2);
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

