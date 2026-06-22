class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return n;
        
        int max_len = 1;
        int left = 0;
        
        for (int right = 1; right < n; right++) {
            // Case 1: The Ugly (Flatline)
            if (arr[right] == arr[right - 1]) {
                left = right; // Hard reset to current element
                continue;
            }
            
            // Case 2: We have at least 3 elements, check if the zig-zag broke
            if (right - left > 1) {
                bool prevUp = arr[right - 1] > arr[right - 2];
                bool currUp = arr[right] > arr[right - 1];
                
                // If the previous direction is the same as the current direction
                if (prevUp == currUp) {
                    left = right - 1; // Soft reset: The last step starts the new window
                }
            }
            
            // Update the maximum window size we've seen
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};