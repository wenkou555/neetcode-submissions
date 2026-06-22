class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int islandArea = 0;
        int row = grid.size();
        if (row == 0) {
            return islandArea;
        }

        int col = grid[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    islandArea = max(islandArea, markIsland(grid, i, j));
                }
            }
        }


        return islandArea;
    }


    int markIsland(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return 0;
        }

        if (grid[i][j] != 1) {
            return 0;
        }

        grid[i][j] = 0;
        return 1 + markIsland(grid, i - 1, j) + markIsland(grid, i + 1, j) + markIsland(grid, i, j - 1) + markIsland(grid, i, j + 1);
    }
};
