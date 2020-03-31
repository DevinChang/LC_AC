#include <bits/stdc++.h>
using namespace std;



vector<int> spiralOrder(vector<vector<int>> &matrix){
    int row = matrix.size();
    if(row < 1) return {};
    int col = matrix[0].size();
    vector<vector<bool>> visit(row, vector<bool>(col, false));
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    int x = 0, y = 0, d = 0;
    vector<int> res;
    for(int i = 0; i < row * col; i++){
        // 一定要先初始化，要不然就会出现重复遍历
        visit[a][b] = true;
        res.push_back(matrix[x][y]);
        int a = x + dx[d], b = y + dy[d];
        if(a < 0 || a >= row || b < 0 || b >= col || visit[a][b]){
            d = (d+1) % 4;
            a = x + dx[d], b = y + dy[d];
        }
        x = a, y = b;
    }
    return res;
}



int main(){


    return 0;
}