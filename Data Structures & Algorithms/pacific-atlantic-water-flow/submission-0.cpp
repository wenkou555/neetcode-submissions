class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int rows = heights.size();
        if (rows == 0)
            return res;
        
        int cols = heights[0].size();

        vector<vector<bool>> pacReach(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlReach(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            dfs(i, 0, heights, pacReach);
            dfs(i, cols - 1, heights, atlReach);
        }


        for (int j = 0; j < cols; j++) {
            dfs(0, j, heights, pacReach);
            dfs(rows - 1, j, heights, atlReach);
        }


        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacReach[i][j] && atlReach[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }

private:
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& tracker) {
        int rows = heights.size();
        if (rows == 0)
            return;

        int cols = heights[0].size();
        if (r < 0 || c < 0 || r >= rows || c >= cols || tracker[r][c])
            return;

        tracker[r][c] = true;

        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (auto& d : dirs) {
            int newR = r + d[0];
            int newC = c + d[1];

            // 4. RECURSION LOGIC
            // We still check bounds here to save a stack frame (optimization),
            // BUT if we missed it, the child call would catch it at Step 1.
            if (newR >= 0 && newR < heights.size() && newC >= 0 && newC < heights[0].size()) {
                
                // The "Uphill" Logic
                if (heights[newR][newC] >= heights[r][c]) {
                    dfs(newR, newC, heights, tracker);
                }
            }
        }

    }
};
