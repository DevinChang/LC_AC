class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		vector<vector<bool>> row(9, vector<bool>(10));
		vector<vector<bool>> col(9, vector<bool>(10));
		vector<vector<bool>> box(9, vector<bool>(10));
		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9; j++) {
				if(board[i][j] == '.') continue;
				int t = board[i][j] - '0';
				if(row[i][t]) return false;
				if(col[j][t]) return false;
				if(box[j / 3 + (i / 3) * 3][t]) return false;
				row[i][t] = true;
				col[j][t] = true;
			    box[j / 3 + (i / 3) * 3][t] = true;
			}
		}
		return true;
    }
};