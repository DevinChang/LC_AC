#include <iostream>
#include <algorithm>
using namespace std;


const int N = 100010;

int heap[N];
int cnt;


void down(int u){
    // 用t来记录父节点，左孩子，右孩子中的最小值的小标
    int t = u;
    // 比较左孩子
    if(u * 2 <= cnt && heap[u * 2] < heap[t]) t = u * 2;
    // 比较右孩子
    if(u * 2 + 1 <= cnt && heap[u * 2 + 1] < heap[t]) t = u * 2 + 1;
    // 若父节点不是最小值，则继续下沉
    if(t != u){
        swap(heap[t], heap[u]);
        down(t);
    }
}





int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &heap[i]);
    cnt = n;
    
    // 建堆
    for(int i = n / 2; i; i--) down(i);

    // 输出最小值
    while(m--){
        printf("%d ", heap[1]);
        heap[1] = heap[cnt--];
        down(1);
    }


    return 0;
}