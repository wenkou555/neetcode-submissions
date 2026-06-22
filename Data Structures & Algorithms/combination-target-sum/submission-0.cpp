class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset = {};
        vector<vector<int>> container = {};
        backtrack(nums, target, 0, 0, subset, container);
        return container;
    }

private:
    void backtrack(vector<int>& nums, int target, int index, int total, vector<int>& subset, vector<vector<int>>& container) {
        if (total > target) {
            return;
        }
        if (total == target) {
            container.push_back(subset);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            backtrack(nums, target, i, total + nums[i], subset, container);

            subset.pop_back();
        }

    }
};
