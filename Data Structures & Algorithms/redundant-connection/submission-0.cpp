class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int rootU = findParent(u);
            int rootV = findParent(v);

            // If they already share the same leader, this edge creates the cycle!
            if (rootU == rootV) {
                return edge;
            }

            // Otherwise, merge them
            parent[rootU] = rootV;
        }

        return {};
        
    }

private:
    vector<int> parent;

    int findParent(int value) {
        if (value == parent[value])
            return value;

        return parent[value] = findParent(parent[value]);
    }
};
