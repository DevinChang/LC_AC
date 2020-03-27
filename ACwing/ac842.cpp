//
// Created by devinchang on 2020/3/14.
//
#include <bits/stdc++.h>
using namespace std;



/* 排列数字 */


const int N = 10;
int path[N];
bool state[N];
int n;


void dfs(int u){
    if(u == n){
        for(int i = 0; i < n; i++) printf("%d ", path[i]);
        puts("");
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!state[i]){
            path[u] = i;
            state[i] = true;
            dfs(u+1);
            state[i] = false;
        }
    }
}







int main(){
    scanf("%d", &n);
    dfs(0);

    vector<int> vec{1, 2, 3};
    auto ret = sol.permute(vec);
    for(auto vv : ret){
        for(auto v : vv) printf("%d ", v);
        printf("\n");
    }


    return 0;
}

