class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {        
        vector<vector<int>> result;
        int n = nums.size();
        if (n == 0)
            return result;

        if (n == 1) {
            result.push_back(nums);
            return result;
        }
        vector<bool> visited(n, false);
        vector<int> permutation;

        sort(nums.begin(), nums.end());
        dfs(nums, permutation, visited, result);

        return result;
    }

private: 
    void dfs(vector<int>& nums, vector<int>& permutation, vector<bool>& visited, vector<vector<int>>& result) {
        if (permutation.size() == visited.size()) {
            result.push_back(permutation);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i])
                continue;

            if (i > 0 && nums[i] == nums[i-1] && !visited[i -1])
                continue;

            visited[i] = true;
            permutation.push_back(nums[i]);

            dfs(nums, permutation, visited, result);

            visited[i] = false;
            permutation.pop_back();
        }

    }
};