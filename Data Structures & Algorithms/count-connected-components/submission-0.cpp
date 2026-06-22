class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int dep = edges[i][0];
            int pre = edges[i][1];
            adj[pre].push_back(dep);
            adj[dep].push_back(pre);
        }

        unordered_set<int> visited;
        queue<int> visitQueue;
        int count = 0;

        for (int j = 0; j < n; j++) {

            if (!visited.count(j)) {
                count++;
                visitQueue.push(j);
                visited.insert(j);
            }

            while (!visitQueue.empty()) {
                int node = visitQueue.front();
                visitQueue.pop();

                for (int neighbours: adj[node]) {

                    if (visited.count(neighbours))
                        continue;

                    visited.insert(neighbours);

                    visitQueue.push(neighbours);
                }
            }
        }

        return count;
    }
};
