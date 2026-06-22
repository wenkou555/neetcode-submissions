class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int index = 0;
        vector<vector<int>> res = {};
        backtrack(nums, index, res);
        return res;
    }

private:
    void backtrack(vector<int>& nums, int index, vector<vector<int>>& res) {
        if (index == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);

            backtrack(nums, index + 1, res);

            swap(nums[i], nums[index]);
        }
    }

};
