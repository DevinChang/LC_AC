//
// Created by devinchang on 2020/3/22.
//

#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int arr[N];
int n, q, k;

typedef pair<int, int> PII;

PII binarySearch(int arr[], int k){
    int l = 0,  r = n - 1;
    while(l < r){
        int mid = l + r >> 1;
        if(arr[mid] >= k) r = mid;
        else l = mid + 1;
    }
    PII ret;
    if(arr[l] != k) ret.first = -1, ret.second = -1;
    else{
        ret.first = l;
        l = 0; r = n -1;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(arr[mid] <= k) l = mid;
            else r = mid-1;
        }
        ret.second = l;
    }
    return ret;
}

int main(){
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    while(q--){
        scanf("%d", &k);
        auto ret = binarySearch(arr, k);
        printf("%d %d\n", ret.first, ret.second);
    }

    return 0;
}

