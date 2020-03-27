//
// Created by devinchang on 2020/3/21.
//

#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int g[N][N];
int d[N][N];
int n,m;

typedef pair<int, int> PII;


int bfs(){
    queue<PII> que;
    memset(d, -1, sizeof d);
    d[0][0] = 0;
    que.push({0, 0});

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while(!que.empty()){
        auto t = que.front();
        que.pop();
        for(int i = 0; i < 4; i++){
            int x = t.first + dx[i], y = t.second + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] ==-1){
                d[x][y] = d[t.first][t.second] + 1;
                que.push({x, y});
            }
        }
    }
    return d[n-1][m-1];
}



int main(){

    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &g[i][j]);
        }
    }

    int res  =  bfs();

    printf("%d\n", res);



    return 0;
}

