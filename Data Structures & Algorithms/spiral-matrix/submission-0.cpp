class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiralVector;

        int top = 0;
        int bottom = matrix.size() - 1;
        if (bottom == -1)
            return spiralVector;

        int left = 0;
        int right = matrix[0].size() - 1; 
        if (right == -1)
            return spiralVector;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                spiralVector.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                spiralVector.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    spiralVector.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    spiralVector.push_back(matrix[i][left]);
                }
                left++;
            }

        }

        return spiralVector;

    }
};
