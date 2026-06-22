class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        if (intervals.size() == 0)
            return result;

        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].size() != 2)
                continue;
            
            if (result.back()[1] < intervals[i][0])
                result.push_back(intervals[i]);
            else {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
        }
        
        return result;
    }
};
