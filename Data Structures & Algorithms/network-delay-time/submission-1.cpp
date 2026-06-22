class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> timeToReach(n + 1, INT_MAX);
        timeToReach[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, k});

        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& time: times) {
            adj[time[0]].push_back({time[1], time[2]});
        }

        while(!minHeap.empty()) {
            int time = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();

            if (timeToReach[node] < time)
                continue;
            
            for (auto& child : adj[node]) {
                if (timeToReach[child.first] > time + child.second) {
                    timeToReach[child.first] = time + child.second;
                    minHeap.push({time + child.second, child.first});
                }
            }
        }


        int finalTime = 0;
        for (int i = 1; i <= n; i++ ) {
            if (timeToReach[i] == INT_MAX)
                return -1;

            finalTime = max(finalTime, timeToReach[i]);
        }

        return finalTime;

        
    }
};
