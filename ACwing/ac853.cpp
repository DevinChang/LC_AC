//
// Created by devinchang on 2020/3/23.
//

#include <bits/stdc++.h>
using namespace std;


const int N = 510, M = 10010;

// bellman-ford 算法只用知道边与边之间的关系，故不需要存储整个图，只需要维护一个关于边的结构就行
// bellman-ford算法的时间复杂度为O(nm)

struct Edge{
    int a, b, c;
}edges[M];

int n, m, k;
int dist[N];
int last[N]; // 备份，防止更新错误


void bellman_ford(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int i = 0; i < k; i++){
        // 更新备份
        memcpy(last, dist, sizeof dist);
        for(int j = 0; j < m; j++){
            auto e = edges[j];
            dist[e.b] = min(dist[e.b], last[e.a] + e.c);
        }
    }
}


int main(){
    scanf("%d%d%d", &n, &m, &k);

    for(int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }

    bellman_ford();

    // 出现负权回路
    if(dist[n] > 0x3f3f3f3f / 2) puts("impossible");
    else printf("%d\n", dist[n]);


    return 0;
}

