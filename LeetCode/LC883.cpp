class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            int r = 0, c = 0;
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) res++;
                r = max(r, grid[i][j]);
                c = max(c, grid[j][i]);
            }
            res += r + c;
        }
        return res;
    }
};