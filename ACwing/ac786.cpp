//
// Created by devinchang on 2020/3/22.
//

#include <bits/stdc++.h>
using namespace std;


const int N = 100010;

int arr[N];



int quicksort(int arr[], int l, int r, int kth){
    if(l >= r) return arr[l];
    int i = l-1, j = r + 1;
    int x = arr[i+j>>1];
    while(i < j){
        while(arr[--j] > x);
        while(arr[++i] < x);
        if(i < j ) swap(arr[i], arr[j]);
    }
    if(j - l + 1 >= kth) return quicksort(arr, l, j, kth);
    else  return quicksort(arr, j+1, r, kth - (j - l + 1));
}



int main(){
    int n, k;
    scanf("%d%d", &n, &k);

    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);


    int ret = quicksort(arr, 0, n-1, k);

    printf("%d\n", ret);



    return 0;
}

