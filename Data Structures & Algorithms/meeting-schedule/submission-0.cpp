/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty())
            return true;

        sort(intervals.begin(), intervals.end(), compInterval);

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < intervals[i-1].end)
                return false;
        }

        return true;
        
    }

private:
    static bool compInterval(const Interval& interval1, const Interval& interval2) {
        return interval1.start < interval2.start;
    }
};
