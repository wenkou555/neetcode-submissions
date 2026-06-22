class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsetVector = {{}};
        for (int& num: nums) {
            int size = subsetVector.size();
            for (int i = 0; i < size; i++) {
                vector<int> subset = subsetVector[i];
                subset.push_back(num);
                subsetVector.push_back(subset);
            }
        }
        return subsetVector;
    }
};
