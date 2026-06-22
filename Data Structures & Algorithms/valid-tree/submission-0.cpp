class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1)
            return false;

        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int dep = edges[i][0];
            int pre = edges[i][1];
            adj[pre].push_back(dep);
            adj[dep].push_back(pre);
        }

        unordered_set<int> visited;
        queue<pair<int, int>> visitQueue;
        visitQueue.push({0, -1});
        visited.insert(0);

        while (!visitQueue.empty()) {
            int node = visitQueue.front().first;
            int source = visitQueue.front().second;

            visitQueue.pop();

            for (int neighbours: adj[node]) {
                if (neighbours == source)
                    continue;

                if (visited.count(neighbours))
                    return false;

                visited.insert(neighbours);

                visitQueue.push({neighbours, node});
            }
        }

        if (visited.size() == n)
            return true;
        else
            return false;
        
    }
};
