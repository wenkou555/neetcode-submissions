class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() != cost.size())
            return -1;

        int curTank = 0;
        int curStart = 0;
        int gasCostDiff = 0;

        for (int i = 0; i < gas.size(); i++) {
            curTank += gas[i] - cost[i];
            if (curTank < 0 ) {
                curTank = 0;
                curStart = i + 1;
            }
            gasCostDiff += gas[i] - cost[i];
        }
        
        if (gasCostDiff < 0)
            return -1;

        return curStart;
    }
};
