//
// Created by devinchang on 2020/3/21.
//

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int h[N], e[N], ne[N], idx;

int d[N]; // 图的度
int q[N]; // 数组模拟队列

int n, m;

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}


bool topsort()
{
    int hh = 0, tt = -1;

    for (int i = 1; i <= n; i ++ )
        if (!d[i])
            q[ ++ tt] = i;

    while (hh <= tt)
    {
        int t = q[hh ++ ];

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (-- d[j] == 0)
                q[ ++ tt] = j;
        }
    }

    return tt == n - 1;
}



int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);

    for(int i = 0; i < m; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        d[b]++;
    }

    if(!topsort()) puts("-1");
    else{
        for(int i = 0; i < n; i++) printf("%d ", q[i]);
        puts("");
    }

    return 0;
}

