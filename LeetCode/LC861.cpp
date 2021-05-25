class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 0){
                for(int j = 0; j < m; j++){
                    grid[i][j] ^= 1;
                }
            }
        }
        int res = (1 << m - 1) * n;
        for(int i = 1; i < m; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(grid[j][i] == 1) cnt++;
            }
            res += (1 << m - 1 - i) * max(cnt, n - cnt);
        }
        return res;
    }
};