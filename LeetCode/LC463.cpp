class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
        int res = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    for(int k = 0; k < 4; k++){
                        int x = dx[k] + i, y = dy[k] + j;
                        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[i].size()) res++;
                        else if(grid[x][y] == 0) res++;
                    }
                }
                
            }
        }
        return res;
    }
};