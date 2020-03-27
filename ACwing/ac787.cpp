#include <iostream>
using namespace std;


const int N = 100010;

int arr[N];
int tmp[N];

int n;

void mergeSort(int arr[], int l, int r){
    if(l >= r) return;
    int mid = l + r >> 1;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);

    int i = l, j = mid + 1;
    int k = 0;
    while(i <= mid && j <= r){
        if(arr[i] <= arr[j]) tmp[k++] = arr[i++];
        else tmp[k++] = arr[j++];
    }
    while(i <= mid) tmp[k++] = arr[i++];
    while(j <= r) tmp[k++] = arr[j++];

    for(int i = l, k = 0; i <= r; i++, k++) arr[i] = tmp[k];
}


int main(){
    scanf("%d", &n);

    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    mergeSort(arr, 0, n-1);

    for(int i = 0;i <n; i++) printf("%d ", arr[i]);

    return 0;
}