#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


const int N = 2010;
int a[N], b[N], c[N];
int t, n, m;

typedef pair<int, int> PII;

void merge(){
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    for(int i = 0; i < n; i++) heap.push({a[0] + b[i], 0});
    for(int i = 0; i < n; i++){
        auto t = heap.top();
        heap.pop();
        c[i] = t.first;
        int idx = t.second;
        heap.push({c[i]-a[idx]+a[idx+1], idx+1});
    }
    memcpy(a, c, sizeof a);
}


int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &m, &n) ;
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a, a+n);
        for(int i = 0; i < m-1; i++){
            for(int i = 0; i < n; i++) scanf("%d", &b[i]);
            merge();
        }
        for(int i = 0; i < n; i++) printf("%d ", a[i]);
        puts("");
    }



    return 0;
}