class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        if (m == 0)
            return n;

        if (n == 0)
            return m;

        vector<vector<int>> mapping(m + 1, vector<int>(n + 1, INT_MAX));

        for (int i = 0; i <= m ; i++) {
            mapping[i][0] = i;
        }

        for (int j = 0; j <= n ; j++) {
            mapping[0][j] = j;
        }

        for (int i = 1; i <= m ; i++) {
            for (int j = 1; j <= n ; j++) { 
                if (word1[i-1] == word2[j-1])
                    mapping[i][j] = mapping[i-1][j-1];
                else 
                    mapping[i][j] = 1 + min(mapping[i-1][j-1], min(mapping[i-1][j], mapping[i][j-1]));   
            }
        }


        return mapping[m][n];
    }
};
