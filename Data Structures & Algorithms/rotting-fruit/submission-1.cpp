class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
            return -1;

        queue<pair<int, int>> distanceQueue;
        int freshCounter = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == ROTTEN) {
                    distanceQueue.push({i,j});
                }
                if (grid[i][j] == FRESH) {
                    freshCounter++;
                }
            }
        }

        int minute = 0;
        while(!distanceQueue.empty()) {

            int queueDistance = distanceQueue.size();
            bool rot = false;

            for (int k = 0; k < queueDistance; k++) {
                int x = distanceQueue.front().first;
                int y = distanceQueue.front().second;
                distanceQueue.pop();
                int fill = grid[x][y];

                if (fillGrid(grid, freshCounter, x - 1, y)) {
                    distanceQueue.push({x - 1, y});
                    rot = true;
                }
                if (fillGrid(grid, freshCounter, x + 1, y)) {
                    distanceQueue.push({x + 1, y});
                    rot = true;
                }
                if (fillGrid(grid, freshCounter, x, y - 1)) {
                    distanceQueue.push({x, y - 1});
                    rot = true;
                }
                if (fillGrid(grid, freshCounter, x, y + 1)) {
                    distanceQueue.push({x, y + 1});
                    rot = true;
                }
            }

            if (rot)
                minute++;
        }

        if (freshCounter == 0)
            return minute;
        else
            return -1;
    }

private:

    const int NOTHING = 0;
    const int FRESH = 1;
    const int ROTTEN = 2;


    bool fillGrid(vector<vector<int>>& grid, int& freshCounter,int i, int j) {
        if (grid.size() == 0) {
            return false;
        }

        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return false;

        if (grid[i][j] == FRESH) {
            grid[i][j] = ROTTEN;
            freshCounter--;
            return true;
        }

        return false;
    }
};

