class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<std::pair<int, int>> postionSpeed;
        for (int i = 0; i < position.size(); i ++) {
            postionSpeed.push_back(make_pair(position[i], speed[i]));
        }

        sort(postionSpeed.rbegin(), postionSpeed.rend());
        int curfleetNumber = 0;
        double slowestTimeInFront = 0.0;

        for (int i = 0; i < postionSpeed.size(); i ++) {
            double currentTime = (double)(target - postionSpeed[i].first) / postionSpeed[i].second;

            if (currentTime > slowestTimeInFront) {
                curfleetNumber++;
                slowestTimeInFront = currentTime;
            }
        }

        return curfleetNumber;

    }
};
