

vector<vector<char>> g;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void dfs(int i, int j) {
    g[i][j] = 0;
    for(int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        if(x >= 0 && x < g.size() && y >= 0 && y < g[0].size() && g[x][y] == '1') dfs(x, y);
    }
}


int numIslands(vector<vector<char>> &grid){
    g = grid;
    int ret = 0;
    int r = grid.size(), c = grid[0].size();
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(g[i][j] == '1') {
                dfs(i, j);
                ret++;
            }
        }
    }
    return ret;
}