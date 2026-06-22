class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        if (heights.empty())
            return maxArea;

        stack<int> indexStack;

        for (int i = 0; i < heights.size(); i++) {
            if (not indexStack.empty() && heights[i] < heights[indexStack.top()])
                {
                while (not indexStack.empty() && heights[indexStack.top()] > heights[i]) {
                    int heightIndex = indexStack.top();
                    indexStack.pop();

                    if (not indexStack.empty())
                        maxArea = max(maxArea, (i - indexStack.top() - 1) * heights[heightIndex]);
                    else {
                        maxArea = max(maxArea, i * heights[heightIndex]);
                    }
                }
            }
            indexStack.push(i);
        }

        int width = heights.size();
        while (not indexStack.empty()) {

            int heightIndex = indexStack.top();
            indexStack.pop();

            if (not indexStack.empty())
                maxArea = max(maxArea, (width - indexStack.top() - 1) * heights[heightIndex]);
            else {
                maxArea = max(maxArea, width * heights[heightIndex]);
            }
        }

        return maxArea;

    }
};
