class Solution {
public:
	bool row[9][9], col[9][9], cell[3][3][9];

	bool dfs(vector<vector<char>>& board, int x, int y) {
		if(y == 9) x++, y = 0;
		if(x == 9) return true;
		if(board[x][y] != '.') return dfs(board, x, y+1);
		for(int i = 0; i < 9; i++) {
			if(!row[x][i] && !col[y][i] && !cell[x/3][y/3][i]) {
				board[x][y] = i + '1';
				row[x][i] = col[y][i] = cell[x/3][y/3][i] = true;
				if(dfs(board, x, y+1)) return true;
				board[x][y] = '.';
				row[x][i] = col[y][i] = cell[x/3][y/3][i] = false;
			}
		}
		return false;
	}

    void solveSudoku(vector<vector<char>>& board) {
		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9; j++) {
				if(board[i][j] != '.') {
					int t = board[i][j] - '1';
					row[i][t] = true;
					col[j][t] = true;
					cell[i / 3][j/3][t] = true;
				}
			}
		}
		dfs(board, 0, 0);
    }
};