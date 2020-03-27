//
// Created by devinchang on 2020/3/23.
//

#include <bits/stdc++.h>
using namespace std;


// dijkstra 求最短路
// 为优化版的时间复杂度为O(n^2)
// 适用于稠密图，即边数大于点数n^2的。稠密图用邻接矩阵存储

const int N = 510;
const int M = 100010;

int g[N][N];
int dist[N];
bool st[N];

int n, m;


int dijkstra(){
    memset(dist, 0x3f, -1);
    dist[1] = 0;

    for(int i = 0; i < n-1; i++){
        // 用t取更新所选边
        int t = -1;
        // 找到不在最短集合中，最短路径的点
        for(int j = 1; j <= n; j++){
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }
        // 更新路径
        for(int j = 1; j <= n; j++){
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }

        st[t] = true;
    }
    // 路径不存在
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main(){
    scanf("%d%d", &n, &m);

    // 初始化图
    memset(g, 0x3f, sizeof g);

    while(m--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        // 存储图，过滤掉重边
        g[a][b] = min(g[a][b], c);
    }

    int ans = dijkstra();

    printf("%d\n", ans);

    return 0;
}

