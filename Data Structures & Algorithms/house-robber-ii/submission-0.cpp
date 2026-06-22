class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        
        if (n == 1)
            return nums[0];

        return max(calculateGains(0, n - 2, nums), 
                   calculateGains(1, n - 1, nums));

    }

private:
    int calculateGains(int start, int end, vector<int>& nums) {
        if (start >= nums.size() || end >= nums.size())
            return -1;

        int prev2 = 0;
        int prev1 = 0;

        for (int i = start; i <= end; i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }


        return prev1;

    }
};
