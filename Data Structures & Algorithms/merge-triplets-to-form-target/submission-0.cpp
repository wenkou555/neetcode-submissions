class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool target1Found = false;
        bool target2Found = false;
        bool target3Found = false;

        for (int i = 0; i < triplets.size(); i++) {
            if (triplets[i][0] == target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2])
                target1Found = true;

            if (triplets[i][0] <= target[0] && triplets[i][1] == target[1] && triplets[i][2] <= target[2])
                target2Found = true;

            if (triplets[i][0] <= target[0] && triplets[i][1] <= target[1] && triplets[i][2] == target[2])
                target3Found = true;
        }

        return target1Found && target2Found && target3Found;
    }
};
