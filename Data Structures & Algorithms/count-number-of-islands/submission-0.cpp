class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0;
        int row = grid.size();
        if (row == 0) {
            return islandCount;
        }

        int col = grid[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    islandCount++;
                    markIsland(grid, i, j);
                }
            }
        }


        return islandCount;
    }


    void markIsland(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return;
        }

        if (grid[i][j] != '1') {
            return;
        }

        grid[i][j] = '0';

        markIsland(grid, i - 1, j);
        markIsland(grid, i + 1, j);
        markIsland(grid, i, j - 1);
        markIsland(grid, i, j + 1);
    }
};
