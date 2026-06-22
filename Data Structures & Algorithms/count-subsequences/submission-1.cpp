class Solution {
public:
    int numDistinct(string s, string t) {
        int i = s.size();
        if (i == 0)
            return 0;

        int j = t.size();
        if (j == 0)
            return 1;

        vector<vector<unsigned int>> cache(i, vector<unsigned int>(j , -1));
        int res = dfs(0, 0, s, t, cache);

        return res;     
    }

private: 
    int dfs(int i, int j, string& s, string& t, vector<vector<unsigned int>>& cache) {
        if (j == t.size())
            return 1;

        if (i == s.size())
            return 0;

        if (cache[i][j] != -1)
            return cache[i][j];

        unsigned int res = 0;
        if (s[i] != t[j]) {
            res = dfs(i + 1, j, s, t, cache);
        } else {
            res = dfs(i + 1, j, s, t, cache) + dfs(i + 1, j + 1, s, t, cache);
        }
        cache[i][j] = res;

        return res;
    }
};
