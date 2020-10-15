//
// Created by devinchang on 2019/12/30.
//
#include "util.h"

int maximalSquare(vector<vector<char>>& matrix){
    int row = matrix.size();
    if (row < 1) return 0;
    int col = matrix[0].size();
    vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
    int ret = 0;
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            if(matrix[i-1][j-1] == '1'){
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1;
                ret = max(dp[i][j], ret);
            }
        }
    }
    return ret * ret;
}

int maximalSquare_old(vector<vector<char>>& matrix){
    int row = matrix.size();
    if(row < 1)
        return 0;
    int col = matrix[0].size();
    int maxlen = 0;
    vector<vector<int>> dp(row, vector<int>(col, 0));
    for(int i = 0; i < row; i++){
        if(matrix[i][0] == '1'){
            dp[i][0] = 1;
            maxlen = 1;
        }
    }
    for(int i = 0; i < col; i++){
        if(matrix[0][i] == '1'){
            dp[0][i] = 1;
            maxlen = 1;
        }
    }
    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            if(matrix[i][j] == '1'){
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1;
                maxlen = max(dp[i][j], maxlen);
            }
        }
    }
    return maxlen * maxlen;
}



int main(){
    vector<vector<char>> matrix{{'1','0','1','0','0'},
                                {'1','0','1','1','1'},
                                {'1','1','1','1','1'},
                                {'1','0','0','1','0'}};
    int ret = maximalSquare(matrix);

    cout << to_string(ret);

    return 0;
}

