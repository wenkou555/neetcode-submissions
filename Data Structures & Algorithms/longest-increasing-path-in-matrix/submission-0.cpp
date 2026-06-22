class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0;
        int m = matrix.size();
        if (m == 0)
            return res;

        int n = matrix[0].size();
        if (n == 0)
            return res;

        vector<vector<int>> cache(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(i, j, -1, matrix, cache, res);
            }
        }

        return res;
    }

private:
    int dfs(int i, int j, int prevVal, vector<vector<int>>& matrix, vector<vector<int>>& cache, int& maxLength) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || matrix[i][j] <= prevVal) {
            return 0;
        }

        if (cache[i][j] != 0)
            return cache[i][j];

        int ret = 0;

        ret = 1 + dfs(i - 1, j, matrix[i][j], matrix, cache, maxLength);
        ret = max(ret, 1 + dfs(i + 1, j, matrix[i][j], matrix, cache, maxLength));
        ret = max(ret, 1 + dfs(i, j - 1, matrix[i][j], matrix, cache, maxLength));
        ret = max(ret, 1 + dfs(i, j + 1, matrix[i][j], matrix, cache, maxLength));

        cache[i][j] = ret;
        maxLength = max(maxLength, ret);

        return ret;

    }
};
