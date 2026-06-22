class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> cache(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dfs(0, 0, s, p, cache);
    }

private:
    bool dfs(int i, int j, string& s, string& p, vector<vector<int>>& cache) {
        if (j == p.size())
            return i == s.size();


        if (cache[i][j] != -1)
            return cache[i][j] == 1;  

        bool match = (i < s.size()) && (s[i] == p[j] || p[j] == '.');
        bool res = false;
        if (j + 1 < p.size() && p[j+1] == '*') {
            res = dfs(i, j + 2, s, p, cache) || (match && dfs(i + 1, j, s, p, cache));
        } else {
            if (match) {
                res = dfs(i + 1, j + 1, s, p, cache);
            }
        }
        cache[i][j] = res ? 1 : 0;
        return res;
    }
};
