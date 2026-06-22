class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> tracker;
   
        for (int i = 0; i < nums.size(); i++) {
            int missingNo = target - nums[i];
            
            if (tracker.find(missingNo) != tracker.end())
                {
                return {tracker[missingNo], i};
                }
            
            tracker[nums[i]] = i;
        }
        
        return {};
    }
};
