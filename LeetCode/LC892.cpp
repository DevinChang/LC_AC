class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) continue;
                // 上下底面
                res += 2;
                for(int k = 0; k < 4; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if(x < 0 || x >= n || y < 0 || y >= n) {
                        res += grid[i][j];
                    }
                    else {
                        res += max(0, grid[i][j] - grid[x][y]);
                    }
                }
            }
        }
        return res;
    }
};