//
// Created by devinchang on 2020/3/23.
//

#include <bits/stdc++.h>
using namespace std;


/* floyd算法求多源最短路,时间复杂度是O(n^3)
 *
 */

const int N = 210;

const int INF = 1e9;

int n, m, k;
int d[N][N]; // 邻接矩阵存储图


void floyd(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}





int main(){
    scanf("%d%d%d", &n, &m, &k);
    // 初始化图
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }

    while(m--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        d[a][b] = min(d[a][b], c);
    }

    floyd();

    while(k--){
        int a, b;
        scanf("%d%d", &a, &b);
        int t= d[a][b];
        if(t > INF / 2) puts("impossible");
        else printf("%d\n", t);
    }



    return 0;
}

