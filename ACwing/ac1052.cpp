#include <bits/stdc++.h>
using namespace std;

const int N = 100010, M = 2 * N;

int h[N], e[M], ne[M], w[M], idx;

int n;
int ans;


void add(int a, int b, int c){
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

int dfs(int u, int p){
    int dist = 0;
    int d1= 0, d2 = 0; // 记录最长和次长的值
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        // 因为遍历树时不可以从孩子返回根节点，故需要定义父节点，防止回溯遍历
        if(j == p) continue;

        int d = dfs(j, u) + w[i];

        dist = max(dist, d);

        if(d >= d1) d2 = d1, d = d1;
        else if(d >= d2) d2 = d;
    }
    ans = max(ans, d1+d2);
    return dist;
}


int main(){
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    // 共有n-1条边
    for(int i = 0; i < n-1; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }

    dfs(1, -1);

    printf("%d\n", ans);


    return 0;
}