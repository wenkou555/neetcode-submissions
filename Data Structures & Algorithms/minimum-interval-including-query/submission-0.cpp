class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<pair<int, int>> queriesByIndex;
        for (int i = 0; i < queries.size(); i++) {
            queriesByIndex.push_back({queries[i], i});
        }

        sort(queriesByIndex.begin(), queriesByIndex.end());

        sort(intervals.begin(), intervals.end());

        vector<int> result(queriesByIndex.size());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        int j = 0;
        for (int i = 0; i < queriesByIndex.size(); i++) {
            int queryValue = queriesByIndex[i].first;
            int indexValue = queriesByIndex[i].second;

            while (j < intervals.size() && intervals[j][0] <= queryValue) {
                minHeap.push({intervals[j][1] - intervals[j][0] + 1, intervals[j][1]});
                j++;
            }

            while (!minHeap.empty() && minHeap.top().second < queryValue) {
                minHeap.pop();
            }

            int res = -1;
            if (!minHeap.empty()) {
               res = minHeap.top().first;
            }

            result[indexValue] = res;

        }

        return result;
    }
};
