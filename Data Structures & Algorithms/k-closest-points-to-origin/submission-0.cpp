class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long, int>> maxHeap;
        
        for (int i = 0; i < points.size(); i++ ) {
            int x = points[i][0];
            int y = points[i][1];

            long distance = (long) x * x + (long) y * y;
            maxHeap.push({distance, i});
            if (maxHeap.size() > k)
               maxHeap.pop();
        }

        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            int index = maxHeap.top().second;
            res.push_back(points[index]);
            maxHeap.pop();
        }


        return res;


    }
};
