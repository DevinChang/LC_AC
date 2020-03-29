#include <bits/stdc++.h>
using namespace std;


/*
两个长度为n的序列a, b，问有多少个区间[l,r]满足如下式子：
max(a[l,r])<min(b[l,r]),0≤l≤r<nmax(a[l,r])<min(b[l,r]),0≤l≤r<n
即a区间的最大值小于b区间的最小值。
数值范围： n<1e5, aibi<1e9
*/

/*
可以用区间dp的方法, 区间dp的经典题目是NOI1995石子合并
*/


const int N = 1e5 + 10;

int a[N], b[N];
int dp_min[N][N], dp_max[N][N];

int n;

int solution(int a[], int b[]){
    // 初始化dp
    for(int i = 0; i < n; i++){
        dp_max[i][i] = a[i][i];
        dp_min[i][i] = b[i][i];
        for(int j = i + 1; j < n; j++){
            dp_max[i][j] = max(dp_max[i][j-1], a[i][j]);
            dp_min[i][j] = min(dp_min[i][j-1], b[i][j]);
        }
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(dp_max[i][j] < dp_min[i][j]) res++;
        }
    }
    return res;
}


int main(){
    scanf("%d%d", &n);
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);
    for(int i = 0; i < N; i++) scanf("%d", &b[i]);

    int ans = solution(a, b);
    printf("%d\n", ans);



    return 0;
}