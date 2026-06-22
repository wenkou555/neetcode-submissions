class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int numJump = 0;
        int farthest = 0;
        int jumpEnd = 0;


        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            if (i == jumpEnd) {
                numJump += 1;
                jumpEnd = farthest;
            }
        }

        return numJump;
    }
};
