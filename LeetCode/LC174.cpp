//
// Created by devinchang on 2019/12/29.
//

#include "util.h"


int calculateMinimumHP_WA(vector<vector<int>> &dungeon){
    int row = dungeon.size();
    if(row < 1)
        return 0;
    int col = dungeon[0].size();
    vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
    int ret = 0;
    dp[0][0] = dungeon[0][0];
    for(int i = 1; i < row; i++){
        dp[i][0] = dp[i-1][0] + (dungeon[i][0] > 0 ? 0 : dungeon[i][0]);
    }
    for(int j = 1; j < col; j++){
        dp[0][j] = dp[0][j-1] + (dungeon[0][j] > 0 ? 0 : dungeon[0][j]);
    }
    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + (dungeon[i][j] > 0 ? 0 : dungeon[i][j]);
        }
    }
    if(dp[row-1][col-1] < 0)
        ret = -dp[row-1][col-1] + 1;
    else
        ret = 1;
    return ret;
}


int calculateMinimumHP(vector<vector<int>> &dungeon){
    int row = dungeon.size();
    if(row < 1)
        return 0;
    int col = dungeon[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));
    dp[row-1][col-1] = max(0, -dungeon[row-1][col-1]);
    for(int i = row-2; i >= 0; i--){
        dp[i][col-1] = max(0, dp[i+1][col-1] - dungeon[i][col-1]);
    }
    for(int j = col-2; j >= 0; j--){
        dp[row-1][j] = max(0, dp[row-1][j+1] - dungeon[row-1][j]);
    }
    for(int i = row-2; i >= 0; i--){
        for(int j = col-2; j >= 0; j--){
            dp[i][j] = max(0, min(dp[i+1][j], dp[i][j+1])-dungeon[i][j]);
        }
    }
    return dp[0][0]+1;
}

int main(){
    vector<vector<int>> dungeon1{{-2,-3,3}, {-5,-10,1}, {10,30,-5}};
    int ret1 = calculateMinimumHP(dungeon1);
    cout << ret1 << endl;

    return 0;
}
