class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        if (r == 0) {
            return;
        }

        int c = board[0].size();

        for (int i = 0; i < r; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);
            if (board[i][c - 1] == 'O' )
                dfs(board, i, c - 1);
        }

        for (int j = 0; j < c; j++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j);
            if (board[r - 1][j] == 'O' )
                dfs(board, r - 1, j);
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '~')
                    board[i][j] = 'O';
            }     
        }
    }

private:
    void dfs(vector<vector<char>>& board, int row, int col) {
        int r = board.size();
        if (r == 0) {
            return;
        }
        int c = board[0].size();

        if (row < 0 || col < 0 || row >= r || col >= c)
            return;

        if (board[row][col] != 'O') 
            return;

        board[row][col] = '~';

        dfs(board, row - 1, col);
        dfs(board, row + 1, col);
        dfs(board, row, col - 1);
        dfs(board, row, col + 1);
    } 
};
