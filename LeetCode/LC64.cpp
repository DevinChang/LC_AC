//
// Created by devinchang on 2019/12/18.
//

#include "util.h"


int minPathSum(vector<vector<int>> &grid){
    int row = grid.size();
    if(row < 1)
        return 0;
    int col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));
    dp[0][0] = grid[0][0];
    for(int i = 1; i < row; i++){
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for(int j = 1; j < col; j++){
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }
    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }
    return dp[row-1][col-1];
}


int main(){
    vector<vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    vector<vector<int>> grid2{{1, 2, 5}, {3, 2, 1}};
    int ret = minPathSum(grid2);
    cout << ret << endl;
    return 0;
}

