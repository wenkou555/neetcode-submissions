class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> combination;
        dfs(1, n, k, combination, res);
        return res;
    }

private:
    void dfs(int curNum, int n, int k, vector<int>& combination, vector<vector<int>>& res) {
        if (combination.size() == k) {
            res.push_back(combination);
            return;
        }

        int remaining = k - combination.size();
        int maxStart = n - remaining + 1;

        for (int i = curNum; i <= maxStart; i++) {
            combination.push_back(i);         
            dfs(i + 1, n, k, combination, res); 
            combination.pop_back();           
        }

    }
};