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
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n == 0)
            return 0;

        vector<int> startVector;
        for (Interval& interval: intervals) {
            startVector.push_back(interval.start);
        }
        vector<int> endVector;
        for (Interval& interval: intervals) {
            endVector.push_back(interval.end);
        }

        sort(startVector.begin(), startVector.end());
        sort(endVector.begin(), endVector.end());

        int maxRoom = 0;
        int usedRoom = 0;
        int s = 0;
        int e = 0;

        while (s < n && e < n) {
            if (startVector[s] >= endVector[e]) {
                usedRoom--;
                e++;
            } else {
                usedRoom++;
                maxRoom = max(maxRoom, usedRoom);
                s++;
            }
        }

        return maxRoom;
    }
};
