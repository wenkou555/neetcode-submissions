class Solution {
public:
    int trap(vector<int>& height) {
        int waterLevel = 0;
        if (height.empty())
            return waterLevel;

        int maxLeft = 0;
        int maxRight = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] <= maxLeft) {
                    waterLevel += maxLeft - height[left];
                } else {
                   maxLeft = height[left];
                }
                left++;
            } else {
                if (height[right] <= maxRight) {
                    waterLevel += maxRight - height[right];
                } else {
                   maxRight = height[right];
                }
                right--;
            }
        }

        return waterLevel;
    }
};
