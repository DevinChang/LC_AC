//
// Created by devinchang on 2020/3/22.
//

#include <bits/stdc++.h>
using namespace std;


const int N = 100010;

int arr[N];

int n;


void quicksort(int arr[], int l, int r){
    if(l >= r) return;

    int i = l - 1, j = r + 1;
    int x = arr[i + j >> 1];
    while(i < j){
        while(arr[--j] > x);
        while(arr[++i] < x);
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    quicksort(arr, l, j);
    quicksort(arr, j+1, r);
}



int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    quicksort(arr, 0, n - 1);

    for(int i = 0; i < n; i++) printf("%d ", arr[i]);


    return 0;
}

