//
// Created by devinchang on 2019/12/19.
//

#include "util.h"


int maximalRectangle(vector<vector<char>> &matrix){
    int row = matrix.size();
    if(row < 1)
        return 0;
    int col = matrix[0].size();
    vector<int> left(col, 0);
    vector<int> right(col, col);
    vector<int> height(col, 0);
    int maxarea = 0;
    for(int i = 0; i < row; i++){
        int curleft = 0, curright = col;
        for(int j = 0; j < col; j++){
            if(matrix[i][j] == '1') {
                height[j]++;
            }
            else {
                height[j] = 0;
            }
        }
        for(int j = 0; j < col; j++){
            if(matrix[i][j] == '1'){
                left[j] = max(curleft, left[j]);
            }
            else{
                left[j] = 0, curleft = j+1;
            }
        }
        for(int j = col-1; j >= 0; j--){
            if(matrix[i][j] == '1'){
                right[j] = min(curright, right[j]);
            }
            else{
                right[j] = col, curright = j;
            }
        }
        for(int j = 0; j < col; j++){
            maxarea = max(maxarea, (right[j]-left[j]) * height[j]);
        }
    }
    return maxarea;
}


int main(){
    vector<vector<char>> matrix{{'1', '0', '1', '0', '0'},
                                {'1', '0', '1', '1', '1'},
                                {'1', '1', '1', '1', '1'},
                                {'1', '0', '0', '1', '0'}};

    int ret = maximalRectangle(matrix);

    cout << ret << endl;
    return 0;
}

