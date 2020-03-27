//
// Created by devinchang on 2020/3/24.
//

#include <bits/stdc++.h>
using namespace std;

/* 差分
 * 记b[n]为原数组的差分，则有b[1] = a[1], b[2] = a[2]-a[1], ..., b[n] = a[n] - a[i]
 * 可以将b[n]看作是前缀和的逆运算. 根据b[n]求a[n],则是a[i] = b[i] + a[i-1],此处可以利用运算
 * 直接赋值为b[i] = b[i] + b[i-1]来简化恢复a[n]的操作
 * 这样的话如果想对区间[l,r]进行操作，只需要对b[l]和b[r+1]进行操作。
 * 这是因为b[l] = b[l] + c, 在求原数组时，区间[l,n]内的所有数都会加上c,故还需要将区间[r+1,n]
 * 减去增加的数b[r+1] = b[r+1] -c
 */

const int N = 100010;

int arr[N];
int b[N];
int n,m;



int main(){
    scanf("%d%d%d", &n, &m, &c);

    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);

    for(int i = 1; i <= n; i++) b[i] = arr[i] - arr[i-1];

    while(m--){
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);

        b[l] += c;
        b[r+1] -= c;
    }

    for(int i = 1; i <= n; i++){
        b[i] = b[i] + b[i-1];
        printf("%d ", b[i]);
    }


    return 0;
}

