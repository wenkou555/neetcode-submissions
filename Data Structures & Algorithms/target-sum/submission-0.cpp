class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int num: nums) {
            totalSum += num;
        }

        if (abs(target) > totalSum) 
            return 0;

        int newTarget = totalSum + target;
        if (newTarget % 2 != 0)
            return 0;

        newTarget = newTarget/2;

        vector<int> wayTracker(newTarget + 1, 0);
        wayTracker[0] = 1;

        for (int num: nums) {
            for (int i = newTarget; i >= num; i--) {
                wayTracker[i] += wayTracker[i - num];
            }
        }

        return wayTracker[newTarget];
    }
};
