//
// Created by devinchang on 2019/12/31.
//
#include "util.h"


int nthUglyNumber_1(int n){
    if(n < 1 || n > 1690)
        return 0;
    vector<long> ugly;
    for(long a = 1; a < INT_MAX; a *= 2){
        for(long b = a; b < INT_MAX; b *= 3){
            for(long c = b; c <INT_MAX; c *= 5){
                ugly.push_back(c);
            }
        }
    }
    sort(ugly.begin(), ugly.end());
    return ugly[n-1];
}


int nthUglyNumber2(int n){
    if(n < 1 || n > 1690)
        return 0;
    int index2 = 0, index3 = 0, index5 = 0;
    vector<int> dp(n, 0);
    dp[0] = 1;
    for(int i = 1; i < n; i++){
        dp[i] = min(dp[index2]*2, min(dp[index3]*3, dp[index5] *5));
        if(dp[i] >= dp[index2]*2)
            index2++;
        if(dp[i] >= dp[index3]*3)
            index3++;
        if(dp[i] >= dp[index5]*5)
            index5++;
    }
    return dp[n-1];
}


int nthUglyNumber(int n) {
    vector<int> q(1, 1);
    for(int i = 0, j = 0, z = 0; q.size() < n;){
        int t = min(q[i] * 2, min(q[j] * 3, q[z] * 5));
        q.push_back(t);
        if(t == q[i] * 2) i++;
        if(t == q[j] * 3) j++;
        if(t == q[z] * 5) z++;
    }
    return q.back();
}

int main(){
    string line;
    while(getline(cin, line)){
        int n = stringToInteger(line);
        int ret = nthUglyNumber(n);
        cout << to_string(ret);
    }

    return 0;
}

