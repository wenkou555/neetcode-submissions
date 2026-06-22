class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int left = 0;
        int current_sum = 0;
        int min_len = INT_MAX; // Start at "infinity"
        
        // Expand the window to the right
        for (int right = 0; right < nums.size(); right++) {
            current_sum += nums[right];
            
            // When the window is valid, shrink it from the left
            while (current_sum >= target) {
                // Record the current window size if it's the smallest so far
                min_len = std::min(min_len, right - left + 1);
                
                // Subtract the left element and move the left pointer forward
                current_sum -= nums[left];
                left++;
            }
        }
        
        // If min_len never changed, we never found a valid window. Return 0.
        return min_len == INT_MAX ? 0 : min_len;
    }
};