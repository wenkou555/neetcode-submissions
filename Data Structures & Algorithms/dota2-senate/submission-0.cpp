class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> dQueue;
        queue<int> rQueue;
        
        int n = senate.size();

        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R')
                rQueue.push(i);
            else
                dQueue.push(i);
        }

        while (!dQueue.empty() && !rQueue.empty()) {
            if (dQueue.front() < rQueue.front()) {
                rQueue.pop();
                dQueue.push(dQueue.front() + n);
                dQueue.pop();
            } else {
                dQueue.pop();
                rQueue.push(rQueue.front() + n);
                rQueue.pop();
            }
        }

        return dQueue.empty() ? "Radiant": "Dire";
    }
};