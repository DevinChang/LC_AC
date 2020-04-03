#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


/*
最长上升子串
*/


const int N  = 100010;
int arr[N];
int dp[N];
int n;


int solution1(){
    int ret = 0;
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j]+1);
        }
        ret = max(ret, dp[i]);
    }
    return ret;
}


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d", &arr[i]);

    int ans = solution1();

    printf("%d\n", ans);




    return 0;
}