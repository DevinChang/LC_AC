class Solution {
public:
    int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int n, m;
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        n = board.size(), m = board[0].size();
        vector<vector<bool>> st(n, vector<bool>(m, false));
        dfs(board, st, click[0], click[1]);
        return board;
    }

    bool dfs(vector<vector<char>> &board, vector<vector<bool>> &st, int x, int y) {
        st[x][y] = true;
        if (board[x][y] == 'M')
        {
            board[x][y] = 'X';
            return true;
        }
        int cnt = 0;
        for (int i = 0; i < 8; i ++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || b < 0 || a >= n || b >= m || st[a][b]) continue;
            if (board[a][b] == 'M') cnt ++;
        }

        if (cnt != 0) board[x][y] = cnt + '0';
        else    
        {
            board[x][y] = 'B';
            for (int i = 0; i < 8; i ++)
            {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || b < 0 || a >= n || b >= m || st[a][b]) continue;
                if (dfs(board, st, a, b)) return true;
            }
        }
        return false;
    }
};