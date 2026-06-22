class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> processedNum;
        for (int i : nums) {
            if (processedNum.find(i) != processedNum.end())
                return true;
            processedNum.insert(i);
        }
        return false;
    }
};