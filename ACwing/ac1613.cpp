#include <iostream>
#include <algorithm>
using namespace std;


const int N = 15;

char g[N][N];
bool row[N][N], col[N][N], cel[N][N][N];


bool dfs(int x, int y){
    if(y == 9){
        return dfs(x+1, 0);
    }
    if(x == 9){
        for(int i = 0; i < 9; i++) puts(g[i]);
        return true;
    }
    if(g[x][y] != '.') return dfs(x, y+1);

    for(int i = 1; i <= 9; i++){
        if(!row[x][i] && !col[y][i] && !cel[x/3][y/3][i]){
            row[x][i] = col[y][i] = cel[x/3][y/3][i] = true;
            g[x][y] = i + '0';
            if(dfs(x, y+1)) return true;
            g[x][y] = '.';
            row[x][i] = col[y][i] = cel[x/3][y/3][i] = false;
        }
    }
    return false;
}




int main(){
    for(int i = 0; i < 9; i++){
        cin >> g[i];
        for(int j = 0; j < 9; j++){
            if(g[i][j] != '.'){
                int t = g[i][j] - '0';
                row[i][t] = col[j][t] = cel[i/3][j/3][t] = true;
            }
        }
    }

    dfs(0, 0);

    return 0;
}