#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


const int N = 100010;
int arr[N];
int n, x;

int dp[2][N];




int solution2(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    dp[0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            dp[i&1][j] = dp[i&1][j-1] ^ arr[i] ^ arr[j];
            //printf("arr[%d] = %d, arr[%d] = %d, dp[%d][%d] = %d\n", i, arr[i], j, arr[j], i&1, j, dp[i&1][j]);
        }
    }

    cout << dp[n&1][n] << endl;
    return 0;
}


int solution1(){
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int st = 0, ed = n-1;
    int res1 = 0, res2 = 0;
    int imin = arr[0], imax = arr[n-1];
    while(st < ed){
        while(arr[ed] - imin > x){
            ed--;
            res1++;
        }
        st++;
    }
    st = 0, ed = n - 1;
    while(st < ed){
        while(imax - arr[st] > x){
            st++;
            res2++;
        }
        ed--;
    }

    cout << res1 << endl;

    return 0;
}


int main(){
    solution2();

    return 0;
}