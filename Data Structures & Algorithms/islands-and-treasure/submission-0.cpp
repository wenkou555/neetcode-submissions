class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
            return;

        queue<pair<int, int>> distanceQueue;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    distanceQueue.push({i,j});
                }
            }
        }

        while(!distanceQueue.empty()) {
            int x = distanceQueue.front().first;
            int y = distanceQueue.front().second;
            distanceQueue.pop();
            int fill = grid[x][y];

            if (fillGrid(grid, x - 1, y, fill + 1))
                distanceQueue.push({x - 1, y});
            if (fillGrid(grid, x + 1, y, fill + 1))
                distanceQueue.push({x + 1, y});
            if (fillGrid(grid, x, y - 1, fill + 1))
                distanceQueue.push({x, y - 1});
            if (fillGrid(grid, x, y + 1, fill + 1))
                distanceQueue.push({x, y + 1});

        }
        
    }

private:
    bool fillGrid(vector<vector<int>>& grid, int i, int j, int fill) {
        if (grid.size() == 0) {
            return false;
        }

        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return false;

        if (grid[i][j] == 2147483647) {
            grid[i][j] = fill;
            return true;
        }

        return false;
    }
};
