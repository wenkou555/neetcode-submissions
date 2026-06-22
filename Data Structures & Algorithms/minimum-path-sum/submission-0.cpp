class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // 1. Initialize the top row (can only come from the left)
        for (int j = 1; j < n; ++j) {
            grid[0][j] += grid[0][j-1];
        }
        
        // 2. Initialize the left column (can only come from the top)
        for (int i = 1; i < m; ++i) {
            grid[i][0] += grid[i-1][0];
        }
        
        // 3. Run your exact logic for the rest of the inner grid
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        // The bottom-right corner now holds the absolute minimum path sum
        return grid[m-1][n-1];
    }
};