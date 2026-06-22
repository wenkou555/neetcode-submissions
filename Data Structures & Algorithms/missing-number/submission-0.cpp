class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int expectedResult = n*(n + 1)/2;

        for (int num: nums) {
            expectedResult -= num;
        }

        return expectedResult;
        
    }
};
