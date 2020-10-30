
void gameOfLife(vector<vector<int>> &board) {
    if(board.empty() || board[0].empty()) return;
    int n = board.size(), m = board[0].size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            int live = 0;
            for(int x = max(0, i-1); x <= min(n-1, i+1); x++){
                for(int y = max(0, j-1); y <= min(m-1, j+1); y++){
                    if((x != i || y != j) && (board[x][y] & 1)) live++;
                }
            }
            int cur = board[i][j] & 1, next;
            if(cur){
                if (live < 2 || live > 3) next = 0;
                else next = 1;
            } else {
                if(live == 3) next = 1;
                else next = 0;
            }
            board[i][j] |= next << 1;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) board[i][j] >>= 1;
    }
}