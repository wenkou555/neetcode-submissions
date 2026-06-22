class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> daysBeforeWarm(temperatures.size(), 0);
        stack<pair<int,int>> tempStack;

        for(int i = 0; i < temperatures.size(); i++) {
            // 1. Pop the cooler days
            // The !empty() check here makes the outer 'if' redundant!
            while (!tempStack.empty() && temperatures[i] > tempStack.top().second) {
                daysBeforeWarm[tempStack.top().first] = i - tempStack.top().first;
                tempStack.pop();
            }
            
            // 2. Always push current day
            tempStack.push({i, temperatures[i]});
        }
        return daysBeforeWarm;
    }
};
