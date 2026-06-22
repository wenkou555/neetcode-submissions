class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        if (m == 0 || n == 0) {
            return 0;
        }

        vector<vector<int>> cache(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    cache[i][j] = cache[i - 1][j - 1] + 1;
                } else {
                    cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
                }
            }
        }


        return cache[m][n];
    }
};
