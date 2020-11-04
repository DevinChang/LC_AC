
class NumMatrix {
public:
    vector<vector<int>> f;
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() < 1 || matrix[0].size() < 1) return;
        int row = matrix.size(), col = matrix[0].size();
        f = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= col; j++){
                f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return f[row2+1][col2+1] - f[row2+1][col1] - f[row1][col2+1] + f[row1][col1];
    }
};
