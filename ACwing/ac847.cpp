//
// Created by devinchang on 2020/3/21.
//
#include <bits/stdc++.h>
using namespace std;



const int N = 1e5+10;

int n, m;
int h[N], e[N], ne[N], idx;
int d[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int bfs()
{
    memset(d, -1, sizeof d);

    queue<int> q;
    d[1] = 0;
    q.push(1);

    while (q.size())
    {
        int t = q.front();
        q.pop();

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (d[j] == -1)
            {
                d[j] = d[t] + 1;
                q.push(j);
            }
        }
    }

    return d[n];
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i ++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    cout << bfs() << endl;

    return 0;
}

