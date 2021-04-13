class Solution {
public:
    vector<vector<int>> g;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    void dfs(int x, int y, int color, int newColor) {
        g[x][y] = newColor;
        for(int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if(a >= 0 && a < g.size() && b >= 0 && b < g[0].size() && g[a][b] == color) 
                dfs(a, b, color, newColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        g = image;
        int color = g[sr][sc];
        if(color == newColor) return g;
        dfs(sr, sc, color, newColor);
        return g;
    }
};