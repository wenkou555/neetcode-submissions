class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> stoneQueue;
        for (int stone: stones) {
            stoneQueue.push(stone);
        }

        while (stoneQueue.size() > 1) {
            int x = stoneQueue.top();
            stoneQueue.pop();
            int y = stoneQueue.top();
            stoneQueue.pop();

            int value = abs(x - y);
            if (value != 0) {
               stoneQueue.push(value); 
            }

        }

        if (stoneQueue.empty()) {
            return 0;
        } else {
            return stoneQueue.top();
        }
        
    }
};
