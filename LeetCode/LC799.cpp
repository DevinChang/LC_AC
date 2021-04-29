class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> f(query_row + 1, vector<double>(query_row+1, 0.0));
        f[0][0] = poured;
        for(int i = 0; i < query_row; i++) {
            for(int j = 0; j <= i; j++) {
                if(f[i][j] > 1) {
                    double x = (f[i][j] - 1) / 2;
                    f[i+1][j] += x, f[i+1][j+1] += x;
                }
            }
        }
        return min(1.0, f[query_row][query_glass]);
    }
};