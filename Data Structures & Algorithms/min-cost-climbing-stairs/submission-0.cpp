class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> cache(cost.size(), -1);
        return min(dfs(0, cost, cache),
                   dfs(1, cost, cache));
    }

private:

    int dfs(int n, vector<int>& cost, vector<int>& cache) {
        if (n >= cost.size())
            return 0;

        if (cache[n] != -1)
            return cache[n];

        cache[n] = cost[n] + min(dfs(n + 1, cost, cache),
                                 dfs(n + 2, cost, cache));

        return cache[n];
    }
};
