class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMax = nums[0];
        int curMin = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curInt = nums[i];

            if (curInt < 0) {
                swap(curMax, curMin);
            }

            curMax = max(curInt, curInt * curMax);
            curMin = min(curInt, curInt * curMin);

            res = max(curMax, res);
        }

        return res;
        
    }
};
