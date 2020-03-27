//
// Created by devinchang on 2019/12/18.
//

#include "util.h"



int uniquePathWithObstacles(vector<vector<int>> &obstacleGrid){
    int row = obstacleGrid.size();
    if(row < 1)
        return 0;
    int col = obstacleGrid[0].size();
    vector<vector<long long>> dp(row, vector<long long>(col, 0));
    dp[0][0] = !(obstacleGrid[0][0] == 1);
    for(int i = 1; i < row; i++){
        dp[i][0] = (obstacleGrid[i][0] == 1 || dp[i-1][0] == 0) ? 0 : 1;
    }
    for(int i = 1; i < col; i++){
        dp[0][i] = (obstacleGrid[0][i] == 1 || dp[0][i-1] == 0) ? 0 : 1;
    }
    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[row-1][col-1];
}


int main(){
    vector<vector<int>> obstacleGrid{{1, 0}};
    vector<vector<int>> obstacleGrid2{{0, 0}, {1,1},{0,0}};
    vector<vector<int>> obstacleGrid3{{0, 0,0}, {0,1,0},{0,0,0}};
    int ret = uniquePathWithObstacles(obstacleGrid3);
    cout << ret << endl;
    return 0;
}
