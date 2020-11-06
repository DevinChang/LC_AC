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


int maxCoins(vector<int> &nums){
    int n = nums.size();
    if(n < 1) return 0;
    vector<int> a(n + 2, 1);
    for(int i = 1; i <= n; i++) a[i] = nums[i-1];
    vector<vector<int>> f(n+2, vector<int>(n+2));
    for(int len = 3; len <= n+2; len++){
        for(int i = 0; i + len - 1 <= n+1; i++){
            int j = i + len - 1;
            for(int k = i+1; k < j; k++){
                f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i] * a[k] * a[j]);
            }
        }
    }
    return f[0][n+1];
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

