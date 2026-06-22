class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; ++i) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;

            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum < target) {
                    left++;
                } 
                else if (sum > target) {
                    right--;
                } 
                else {
                    // Found a valid triplet
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for left
                    while (left < right && nums[left] == nums[left + 1])
                        left++;

                    // Skip duplicates for right
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    // Move both after recording
                    left++;
                    right--;
                }
            }
        }

        return result;
    }
};
