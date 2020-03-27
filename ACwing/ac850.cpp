//
// Created by devinchang on 2020/3/23.
//

#include <bits/stdc++.h>
using namespace std;


/* dijkstra优化版算法，时间复杂度为O(nlogm)
 * 适用于稀疏图。稀疏图的存储用邻接表
 */

const int N = 100010;

int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];

// 用堆优化。优先队列里存的的是当前的点和距离
typedef pair<int, int> PII;


int n, m;


void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    // 最小堆. first表示的是距离，second是点
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    while(heap.size()){
        auto t = heap.top();
        heap.pop();

        int ver = t.second;
        int d = t.first;
        // ver节点已经是最短路径
        if(st[ver]) continue;
        st[ver] = true;

        for(int i = h[ver]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > d + w[i]){
                dist[j] = d + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
}


int main(){
    scanf("%d%d", &n, &m);
    // 切记要初始化邻接表，防止死循环
    memset(h, -1, sizeof h);
    while(m--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    int ans = dijkstra();

    printf("%d\n", ans);


    return 0;
}

