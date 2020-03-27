//
// Created by devinchang on 2020/3/21.
//

#include <bits/stdc++.h>
using namespace std;


const int N = 1e5 + 10, M = 2 * N;
// 图的邻接表存储
int h[N], e[M], ne[M], idx;

int ans = N;
bool st[N];

int n;




void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u){
    st[u] = true;
    int size = 0, sum = 0;
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(st[j]) continue;

        int s = dfs(j);
        size = max(size, s);
        sum += s;
    }

    // 计算根节点处遍历节点的数目
    size = max(size, n - sum - 1);
    ans = min(ans, size);

    return sum+1;

}


int main(){
    scanf("%d", &n);
    memset(h, -1, sizeof h);

    for(int i = 0; i < n-1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }

    dfs(1);

    printf("%d\n", ans);


    return 0;
}

