//
// Created by devinchang on 2019/12/31.
//
#include "util.h"


int numSquares(int n){
    if(n < 1)
        return 0;
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    for(int i = 1; i <= n; i++){
        dp[i] = i;
        for(int j = 1; i - j * j >= 0; j++){
            dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
    }
    return dp[n];
}



int numSquares(int n) {
    if ((int)sqrt(n) * (int)sqrt(n) == n)
        return 1;
    int t = n;
    while ((t & 3) == 0) t >>= 2;
    if (((t - 7) & 7) == 0)
        return 4;

    for (int i = 1; i * i <= n; i++)
        if ((int)(sqrt(n - i * i)) * (int)(sqrt(n - i * i)) == n - i * i)
            return 2;

    return 3;
}




int main(){
    string line;
    while(getline(cin, line)){
        int n = stringToInteger(line);
        int ret = numSquares(n);
        cout << to_string(ret) << endl;
    }

    return 0;
}

