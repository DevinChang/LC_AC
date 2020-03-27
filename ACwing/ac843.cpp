//
// Created by devinchang on 2020/3/14.
//

#include <bits/stdc++.h>
using namespace std;


const int N = 20;
char g[N][N];

bool row[N], col[N], dg[N], udg[N];

int n;


void dfs(int u){
    if(u == n){
        for(int i = 0; i < n; i++) puts(g[i]);
        puts("");
        return;
    }

    for(int i = 0; i < n; i++){
        if(!col[i] && !dg[-u + n + i] && !udg[u + i]){
            g[u][i] = 'Q';
            col[i] = dg[-u + n + i] = udg[u + i] = true;
            dfs(u + 1);
            col[i] = dg[-u + n + i] = udg[u + i] = false;
            g[u][i] = '.';
        }

    }
}


void dfs(int x, int y, int s){
    if(s > n) return;
    if(y == n){
        y = 0;
        x++;
    }
    if(x == n){
        if(s == n){
            for(int i = 0; i < n; i++) puts(g[i]);
            puts("");
        }
        return;
    }
    g[x][y] = '.';
    dfs(x, y+1, s);

    if(!row[x] && !col[y] && !dg[-x + y + n] && !udg[x + y]){
        g[x][y] = 'Q';
        row[x] = col[y] = dg[-x + y + n] = udg[x+y] = true;
        dfs(x, y+1, s+1);
        row[x] = col[y] = dg[-x + y + n] = udg[x+y] = false;
        g[x][y] = '.';


    }
}


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            g[i][j] = '.';
    }
    //dfs(0);
    dfs(0, 0, 0);

    return 0;
}

