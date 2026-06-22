class Solution {
public:
    int climbStairs(int n) {
        vector<int> cache(n, -1);
        return dfs(0, n, cache);
    }

private:
    int dfs(int x, int n, vector<int>& cache) {
        if (x == n)
            return 1;

        if (x > n)
            return 0;

        if (cache[x] != -1)
            return cache[x];

        cache[x] = dfs(x + 1, n, cache) + dfs(x + 2, n, cache);
        return cache[x];
    }

};
