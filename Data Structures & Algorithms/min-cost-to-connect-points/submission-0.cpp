class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<bool> visited(points.size(), false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        minHeap.push({0, 0});
        int cost = 0;
        int edgesFound = 0;

        while (!minHeap.empty()) {
            int distance = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();
            if (visited[node])
                continue;

            visited[node] = true;
            cost += distance;
            edgesFound++;
            if (edgesFound == points.size())
                break;

            for (int i = 0; i < points.size(); i++) {
                if (visited[i])
                    continue;
                
                int dist = manhattanDist(points[node], points[i]);
                minHeap.push({dist, i});
            }

        }

        return cost;  
    }

private: 
    int manhattanDist(vector<int>& point1, vector<int>& point2) {
        return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1]); 
    }
};
