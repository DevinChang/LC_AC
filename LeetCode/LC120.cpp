//
// Created by devinchang on 2019/12/23.
//

#include "util.h"


int minimumTotal(vector<vector<int>> &triangle){
    int row = triangle.size();
    if(row < 1)
        return 0;
    int col = triangle[0].size();
    vector<int> dp(triangle.back());
    for(int layer = row - 2; layer >= 0; layer--){
        for(int i = 0; i <= layer; i++){
            dp[i] = min(dp[i], dp[i+1]) + triangle[layer][i];
        }
    }
    return dp[0];
}



int main(){
    vector<vector<int>> triangle{{2}, {3,4}, {6, 5, 7}, {4, 1, 8, 3}};
    int ret = minimumTotal(triangle);
    cout << ret << endl;
    return 0;
}

