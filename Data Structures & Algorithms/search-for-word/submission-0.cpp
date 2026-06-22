class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        if (rows == 0) 
            return false;
        int cols = board[0].size();
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == word[0]) {
                    ///call funct
                    if (findWord(board, word, r, c, 0)) {
                        return true;
                    } 
                }
            }
        } 
        return false;
    }

private:
    bool findWord(vector<vector<char>>& board, string& word, int row, int col, int index) {
        if (index == word.size())
            return true;

        if (row < 0 or 
            col < 0 or
            row >= board.size() or
            col >= board[0].size() or
            board[row][col] != word[index]) {
                return false;
            }
        
        char temp = board[row][col];
        board[row][col] = '~';

        bool match = findWord(board, word, row + 1, col, index + 1) or
                     findWord(board, word, row - 1, col, index + 1) or
                     findWord(board, word, row, col + 1, index + 1) or
                     findWord(board, word, row, col - 1, index + 1);

        board[row][col] = temp;

        return match;

    }
};
