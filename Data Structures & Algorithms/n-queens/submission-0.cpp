class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false);
        vector<bool> diagonal(2*n - 1, false);
        vector<bool> reverseDiagonal(2*n - 1, false);
        placeQueens(result, board, cols, diagonal, reverseDiagonal, 0);
        return result;
    }

private:
    void placeQueens(vector<vector<string>>& result, 
                     vector<string>& board,
                     vector<bool>& cols,  
                     vector<bool>& diagonal,  
                     vector<bool>& reverseDiagonal,
                     int row) {

        int n = board.size();
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            int diagId = row + col;
            int revDiagId = (row - col) + (n - 1);

            if (cols[col] || diagonal[diagId] || reverseDiagonal[revDiagId]) {
                continue; 
            }

            board[row][col] = 'Q';
            cols[col] = true;
            diagonal[diagId] = true;
            reverseDiagonal[revDiagId] = true;

            placeQueens(result, board, cols, diagonal, reverseDiagonal, row + 1);

            board[row][col] = '.';
            cols[col] = false;
            diagonal[diagId] = false;
            reverseDiagonal[revDiagId] = false;
        }
    }
};
