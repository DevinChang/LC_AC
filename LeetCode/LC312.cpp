//
// Created by devinchang on 2020/1/3.
//
#include "util.h"


int maxCoins(vector<int> &nums, int left, int right, vector<vector<int>> &cache){
    if(left + 1 == right)
        return 0;
    if(cache[left][right] != -1)
        return cache[left][right];
    int maxcoin = 0;
    for(int i = left+1; i < right; i++){
        maxcoin = max(maxcoin, maxCoins(nums, left, i, cache) + maxCoins(nums, i, right, cache)
                               + nums[left] * nums[i] * nums[right]);
    }
    cache[left][right] = maxcoin;
    return maxcoin;
}


int maxCoins(vector<int> &nums){
    int len = nums.size();
    if(len < 1)
        return 0;
    vector<int> bullo(len+2, 0);
    bullo[0] = 1;
    int i = 1;
    for(auto n : nums){
        bullo[i++] = n;
    }
    bullo[i++] = 1;
    vector<vector<int>> cache(i, vector<int>(i, -1));
    return maxCoins(bullo, 0, i-1, cache);
}




int main(){
    string line;
    while(getline(cin, line)){
        vector<int> nums = stringToIntegerVector(line);
        int ret = maxCoins(nums);
        cout << to_string(ret) << endl;
    }

    return 0;
}

