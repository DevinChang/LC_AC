class Solution {
public:
    /*
    1. 如果只能存储一行，也可以判断，因为只需要每次判断[i,j]与[i-1,j-1]的元素是否想相同，之后，每次遍历的时候
       循环删除。这样只需要存储n+2个元素
    2. 可以利用分治思想来做。
    */
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[i].size(); j++) {
                if(matrix[i][j] != matrix[i-1][j-1]) return false;
            }
        }
        return true;
    }
};