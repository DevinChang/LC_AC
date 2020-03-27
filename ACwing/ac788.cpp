//
// Created by devinchang on 2020/3/22.
//

#include <bits/stdc++.h>
using namespace std;


const int N = 100010;
int arr[N];
int tmp[N];

int n;

typedef long long LL;

LL mergeSort(int arr[],int l, int r){
    if(l >= r) return 0;
    int mid = l + r >> 1;
    LL ret = mergeSort(arr, l, mid) + mergeSort(arr, mid+1, r);

    int i = l, j = mid+1;
    int k = 0;
    while(i <= mid && j <= r){
        if(arr[i] <= arr[j]) tmp[k++] = arr[i++];
        else{
            ret += mid - l + 1;
            tmp[k++] = arr[j++];
        }
    }

    for(int i = l, k = 0; i <= r; i++, k++) arr[i] = tmp[k];

    return ret;

}


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int ret = mergeSort(arr, 0, n-1);
    printf("%d\n", ret);
    return 0;
}

