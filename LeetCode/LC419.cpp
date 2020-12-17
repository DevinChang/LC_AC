class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(i > 0 && board[i-1][j] == 'X') continue;
                if(j > 0 && board[i][j-1] == 'X') continue;
                if(board[i][j] == 'X') res++;
            }
        }
        return res;
    }
};