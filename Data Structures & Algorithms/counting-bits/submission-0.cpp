class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> returnVector(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            returnVector[i] = returnVector[i & (i - 1)] + 1;
        }

        return returnVector;
        
    }
};
