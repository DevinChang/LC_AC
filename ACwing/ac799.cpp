//
// Created by devinchang on 2020/3/24.
//

#include <bits/stdc++.h>
using namespace std;



const int N = 100010;

int arr[N], tmp[N];


int n;


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);


    int ans = 1;
    for(int i = 0, j = 0; i < n; i++){
        tmp[arr[i]]++;
        while(j < i && tmp[arr[i]] > 1)
            tmp[arr[j++]]--;
        ans = max(ans, i - j + 1);
    }

    printf("%d\n", ans);


    return 0;
}
