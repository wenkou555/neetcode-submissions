class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int bottleneck = 0;
        int m = grid.size();
        if (m == 0)
            return bottleneck;
        
        int n = grid[0].size();
        if (n == 0)
            return bottleneck;

        bottleneck = grid[0][0]; 
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({grid[0][0], 0, 0});
        visited[0][0] = true;


        while (!minHeap.empty()) {
            vector<int> coordinates = minHeap.top();
            minHeap.pop();
            bottleneck = max(coordinates[0], bottleneck);
            int x = coordinates[1];
            int y = coordinates[2];

            if (x == m-1 && y == n-1)
                return bottleneck;

            if (x - 1 >= 0 && !visited[x - 1][y]) {
                minHeap.push({grid[x-1][y], x-1, y});
                visited[x-1][y] = true;
            }

            if (y - 1 >= 0 && !visited[x][y -1]) {
                minHeap.push({grid[x][y-1], x, y-1});
                visited[x][y-1] = true;
            }

            if (x + 1 < m && !visited[x + 1][y]) {
                minHeap.push({grid[x + 1][y], x + 1, y});
                visited[x+1][y] = true;
            }

            if (y + 1 < n && !visited[x][y + 1]) {
                minHeap.push({grid[x][y+1], x, y+1});
                visited[x][y+1] = true;
            }

        }

        return bottleneck;

    }
};
