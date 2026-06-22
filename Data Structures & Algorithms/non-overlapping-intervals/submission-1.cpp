class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int zapCounter = 0;
        int lastIntervalEnd = INT_MIN;

        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] >= lastIntervalEnd)
                lastIntervalEnd = intervals[i][1];
            else {
                zapCounter++;
                lastIntervalEnd = min(lastIntervalEnd, intervals[i][1]);
            }
        }
        return zapCounter;
    }
};
