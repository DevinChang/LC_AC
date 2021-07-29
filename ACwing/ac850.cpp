#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int N = 100010;

typedef pair<int,int> PII;

vector<vector<PII>> g;
int d[N];
bool st[N];
int n, m;

int dijkstra() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    while(heap.size()) {
        PII t = heap.top();
        heap.pop();
        int ver = t.second, dst = t.first;
        if(st[ver]) continue;
        st[ver] = true;
        for(auto &ga : g[ver]) {
            if(d[ga.first] > d[ver] + ga.second) {
                d[ga.first] = d[ver] + ga.second;
                heap.push({d[ver] + ga.second, ga.first});
            }
        }
    }
    if(d[n] == 0x3f3f3f3f) return -1;
    return d[n];
}

int main() {
    cin >> n >> m;
    g.resize(n+1);
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    cout << dijkstra() << endl; 

    return 0;
}