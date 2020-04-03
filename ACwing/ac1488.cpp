#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

/*
村庄最短距离
*/


const int N = 100010, M = 300010;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], q[N];
bool st[N];
int n, m, k;

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void spfa(){
    int hh = 0, tt = 0;
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    st[0] = false;
    // 超级源点入队列
    q[tt++] = 0;

    while(hh != tt){
        int t = q[hh++];
        if(hh == N) hh = 0;
        st[t] = false;

        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                if(!st[j]){
                    st[j] = true;
                    q[tt++] = j;
                    if(tt == N) tt = 0;
                }
            }
        }
    }
}


int main(){
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);
    while (m -- )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }

    scanf("%d", &m);
    // 为每个商店增加超级源点
    while (m -- )
    {
        int v;
        scanf("%d", &v);
        add(0, v, 0);
    }

    spfa();

    scanf("%d", &m);
    while (m -- )
    {
        int v;
        scanf("%d", &v);
        printf("%d\n", dist[v]);
    }

    return 0;
}