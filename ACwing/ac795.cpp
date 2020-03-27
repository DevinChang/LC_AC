//
// Created by devinchang on 2020/3/24.
//

#include <bits/stdc++.h>
using namespace std;


/* 前缀和
*/


const int N = 100010;

int arr[N];
int S[N];

int n, m;



int main(){
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        S[i] = S[i-1] + arr[i];
    }

    while(m--){
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", S[r] - S[l-1]);
    }






    return 0;
}

