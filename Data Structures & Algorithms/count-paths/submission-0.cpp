class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) {
            return 0;
        }

        if (m == 1 || n == 1) {
            return 1;
        }

        vector<vector<int>> cache(m, vector<int>(n));

        int i = 0;
        while (i < m) {
          cache[i][0] = 1;
          i++;  
        }

        i = 0;
        while (i < n) {
          cache[0][i] = 1;
          i++;  
        }

        for (int j = 1; j < m; j++) {
            for (int k = 1; k < n; k++) {
                cache[j][k] = cache[j - 1][k] + cache[j][k - 1];
            }
        }


        return cache[m-1][n-1];
    }
};
