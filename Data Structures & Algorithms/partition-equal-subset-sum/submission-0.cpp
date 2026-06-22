class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int num : nums)
            total += num;
        
        if (total % 2 != 0) {
            return false;
        } 

        int target = total/2;
        vector<bool> sumTracker(target + 1, false);
        sumTracker[0] = true;

        for (int num : nums) {
            for (int i = target; i >= num; i--) {
                if (sumTracker[i - num])
                    sumTracker[i] = true;
            }
        }

        return sumTracker[target];
    }
};
