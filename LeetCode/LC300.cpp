//
// Created by devinchang on 2019/12/31.
//
#include "util.h"


int lengthOfLIS(vector<int> &nums){
    int len = nums.size();
    if(len < 1)
        return 0;
    int maxlen = 1;
    vector<int> dp(len, 1);
    for(int i = 0; i < len; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        maxlen = max(maxlen, dp[i]);
    }
    return maxlen;
}


int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> q;
    for(auto x : nums){
        if(q.empty() || x > q.back()) q.push_back(x);
        else {
            if(x <= q[0]) q[0] = x;
            else {
                int l = 0, r = q.size()-1;
                while(l < r){
                    int mid = (l + r+1) / 2;
                    if(q[mid] < x) l = mid;
                    else r = mid - 1;
                }
                q[r+1] = x;
            }
        }
    }
    return q.size();
}

int main(){
    string line;
    while(getline(cin, line)){
        vector<int> nums = stringToIntegerVector(line);
        int ret = lengthOfLIS(nums);
        cout<< to_string(ret) << endl;
    }

    return 0;
}

