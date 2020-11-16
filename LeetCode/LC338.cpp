//
// Created by devinchang on 2020/1/3.
//
#include "util.h"


vector<int> countBits(int num){
    if(num < 0)
        return {};
    vector<int> dp(num+1, 0);
    for(int i = 1; i <= num; i++){
        dp[i] = dp[i&(i-1)] + 1;
    }
    return dp;
}

vector<int> countBits(int num) {
    vector<int> f(nums+1, 0);
    for(int i = 1; i <= num; i++){
        f[i] = f[i >> 1] + (i & 1);
    }
    return f;
}



int main(){
    auto ret = countBits(5);
    for(auto n : ret)
        cout << n << " ";
    cout << endl;

    return 0;
}

