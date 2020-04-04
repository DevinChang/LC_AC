#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


/*
最长上升子串: 删除一个元素后，剩下的最长上升子序列是多少？
需要注意的是，如leetcode的最长上升子序列不同的是，此题需要删除一个元素，即
不计算某个元素时的长度
*/


const int N  = 100010;
int arr[N];
int dp[N];
int f[N], g[N];
int n;


int solution2(){
    int ret = 0;
    for(int i = 1; i <= n; i++){
        if(arr[i-1] < arr[i]) f[i] = f[i-1]+1;
        else f[i] = 1;
    }

    for(int i = n; i >= 0; i--){
        if(arr[i] < arr[i+1]) g[i] = g[i+1] + 1;
        else g[i] = 1;
    }

    for(int i = 1; i <= n; i++){
        if(arr[i-1] < arr[i+1]) ret = max(ret, f[i-1]+g[i+1]);
        else ret = max(ret, max(f[i-1], g[i+1]));
    }
    return ret;
}


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
    for(int i = 1; i <= n; i ++) scanf("%d", &arr[i]);

    int ans = solution1();

    printf("%d\n", ans);




    return 0;
}