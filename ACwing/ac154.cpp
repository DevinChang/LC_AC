//
// Created by devinchang on 2020/3/13.
//
#include <bits/stdc++.h>
using namespace std;


/* 滑动窗口 */


const int N = 1000010;

int arr[N];
int q[N];
int hh = 0, tt = -1;

int n, k;


int main(){
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for(int i = 0; i < n; i++){
        // 移动窗口
        if(hh <= tt && i - k + 1 > q[hh]) hh++;
        while(hh <= tt && arr[q[tt]] >= arr[i]) tt--;
        q[++tt] = i;

        if(i >= k - 1)
            printf("%d ", arr[q[hh]]);
    }

    printf("\n");

    hh = 0, tt = -1;

    for(int i = 0; i < n; i++){
        if(hh <= tt && i - k + 1 > q[hh]) hh++;
        while(hh <= tt && arr[q[tt]] <= arr[i]) tt--;
        q[++tt] = i;

        if(i >= k - 1) printf("%d ", arr[q[hh]]);
    }

    return 0;
}

