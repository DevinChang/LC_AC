#include <iostream>
#include <algorithm>
using namespace std;


const int N = 100010;

int arr[N];
int n;



int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    sort(arr, arr+n);

    int mid = arr[n/2];

    int ans = 0;
    
    for(int i = 0; i < n; i++) ans += abs(arr[i] - mid);


    printf("%d\n", ans);
    



    return 0;
}