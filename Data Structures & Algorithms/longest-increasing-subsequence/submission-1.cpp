class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 1;
        vector<int> subsequenceLenght(n + 1, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    subsequenceLenght[i] = max(subsequenceLenght[j] + 1, subsequenceLenght[i]);
                }
            }
            maxLength = max(maxLength, subsequenceLenght[i]);
        }

        return maxLength;
        
    }
};
