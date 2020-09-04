//
// Created by devinchang on 2019/12/27.
//

#include "util.h"



int maxProduct(vector<int> &nums) {
    int res = nums[0];
    int f = nums[0], g = nums[0];
    for (int i = 1; i < nums.size(); i ++ ) {
        int a = nums[i], fa = f * a, ga = g * a;
        f = max(a, max(fa, ga));
        g = min(a, min(fa, ga));
        res = max(res, f);
    }
    return res;;
}


int maxProduct_2DP(vector<int> &nums){
    int len = nums.size();
    if(len < 1)
        return 0;
    int ret = nums[0];
    vector<int> dpmax(len, 1);
    vector<int> dpmin(len, 1);
    dpmax[0] = dpmin[0] = nums[0];
    for(int i = 1; i < len; i++){
        dpmax[i] = max(nums[i], max(dpmax[i-1] * nums[i], dpmin[i-1] * nums[i]));
        dpmin[i] = min(nums[i], min(dpmax[i-1] * nums[i], dpmin[i-1] * nums[i]));
        ret = max(ret, dpmax[i]);
    }
    return ret;
}


int maxProduct_1DP(vector<int> &nums){
    int len = nums.size();
    if(len < 1)
        return 0;
    int ret = nums[0];
    int imax = 1, imin = 1;
    for(int i = 0; i < len; i++){
        if(nums[i] < 0){
            int tmp = imax;
            imax = imin;
            imin = tmp;
        }
        imax = max(nums[i]*imax, nums[i]);
        imin = min(nums[i]*imin, nums[i]);
        ret = max(ret, imax);
    }
    return ret;
}

int maxProduct(vector<int> &nums){
    int len = nums.size();
    if(len < 1)
        return 0;
    int imax = 1, ret = nums[0];
    for(int i = 0; i < len; i++){
        imax *= nums[i];
        ret = max(ret, imax);
        if(imax == 0){
            imax = 1;
        }
    }
    imax = 1;
    for(int i = len-1; i >= 0; i--){
        imax *= nums[i];
        ret = max(ret, imax);
        if(imax == 0){
            imax = 1;
        }
    }
    return ret;
}

int main(){
    string line;
    while(getline(cin, line)){
        vector<int> nums = stringToIntegerVector(line);

        int ret = maxProduct(nums);

        cout << ret << endl;
    }

    return 0;
}

