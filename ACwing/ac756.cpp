#include <bits/stdc++.h>
using namespace std;


/*
蛇形矩阵
 */


const int N = 110;

int arr[N][N];
int n, m;



int main(){
    scanf("%d%d", &n, &m);
    int x = 0, y = 0;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    int d = 0;
    for(int i = 1; i <= n * m; i++){
        arr[x][y] = i;
        int a = x + dx[d], b = y + dy[d];
        if(a < 0 || a >= n || b < 0 || b >= m || arr[a][b]){
            d = (d + 1) % 4;
            a = x+dx[d], b = y + dy[d];
        }
        x = a, y = b;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) printf("%d ", arr[i][j]);
        printf("\n");
    }

    return 0;
}