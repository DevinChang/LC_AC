#include <iostream>
using namespace std;


const int N = 10;
int path[N];
bool st[N];
int n;


void dfs(int u) {
    if(u == n) {
        for(int i = 0; i < n; i++) printf("%d ", path[i]);
        printf("\n");
        return;
    }
    for(int i = 0; i < n; i++) {
        if(!st[i]) {
            path[u] = i+1;
            st[i] = true;
            dfs(u+1);
            st[i] = false;
        }
    }
}


int main() {
    scanf("%d", &n);
    dfs(0);
    return 0;
}