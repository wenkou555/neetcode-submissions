class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> subset = {};
        vector<vector<int>> container = {};
        sort(nums.begin(), nums.end());
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
            if (i > index && nums[i] == nums[i -1])
                continue;
            subset.push_back(nums[i]);
            backtrack(nums, target, i + 1, total + nums[i], subset, container);

            subset.pop_back();
        }

    }
};
