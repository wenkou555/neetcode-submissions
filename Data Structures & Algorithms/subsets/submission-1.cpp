class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset = {};
        vector<vector<int>> subsetVector = {};
        backtrack(nums, subsetVector, subset, 0);
        return subsetVector;

    }

private:
    void backtrack(vector<int>& nums, vector<vector<int>>& container, vector<int>& subset, int index) {
        container.push_back(subset);

        for (int i = index; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            backtrack(nums, container, subset, i + 1);
            subset.pop_back();
        }
    }
};
