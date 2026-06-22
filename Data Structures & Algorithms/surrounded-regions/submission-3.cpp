class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        if (r == 0) {
            return;
        }

        int c = board[0].size();

        queue<pair<int, int>> oQueue;

        for (int i = 0; i < r; i++) {
            if (board[i][0] == 'O') {
                oQueue.push({i, 0});
                board[i][0] == '~';
            }
            if (board[i][c - 1] == 'O' ) {
                oQueue.push({i, c - 1});
                board[i][c - 1] == '~';
            }
        }

        for (int j = 0; j < c; j++) {
            if (board[0][j] == 'O') {
                oQueue.push({0, j});
                board[0][j] == '~';
            }
            
            if (board[r - 1][j] == 'O' ) {
                oQueue.push({r - 1, j});
                board[r - 1][j] == '~';
            }
        }

        bfs(board, oQueue);

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

    void bfs(vector<vector<char>>& board, queue<pair<int, int>>& oQueue) {
        if (oQueue.size() == 0)
            return; 

        int r = board.size();
        if (r == 0) {
            return;
        }
        int c = board[0].size();

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!oQueue.empty()) {
            int x = oQueue.front().first;
            int y = oQueue.front().second;
            oQueue.pop();

            board[x][y] = '~';

            for (auto& direction : directions) {
                int xp = x + direction.first;
                int yp = y + direction.second;

                if (xp < 0 || yp < 0 || xp >= r || yp >= c)
                    continue;

                if (board[xp][yp] != 'O')
                    continue;

                oQueue.push({xp, yp});
            }

        }

    } 
};
