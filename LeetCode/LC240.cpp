

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    int row = matrix.size(), col = matrix[0].size();
    for(int i = 0, j = col-1; i < row && j >= 0;){
        int t = matrix[i][j];
        if (t == target) return true;
        else if (t > target) j -- ;
        else i ++ ;
    }
    return false;
}