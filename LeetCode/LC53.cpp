//
// Created by devinchang on 2019/12/17.
//

#include "util.h"


int maxSubArray(vector<int> &nums){
    if(nums.size() < 1)
        return 0;
    int len = nums.size();
    vector<int> dp(len, 0);
    dp[0] = nums[0];
    int ret = nums[0];
    for(int i = 1; i < len; i++){
        dp[i] = max(nums[i], dp[i-1] + nums[i]);
        ret = max(dp[i], ret);
    }
    return ret;
}


int main(){
    string line;
    while(getline(cin, line)){
        vector<int> nums = stringToIntegerVector(line);

        int ret = maxSubArray(nums);
        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

