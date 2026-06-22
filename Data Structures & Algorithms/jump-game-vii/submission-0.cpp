class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s[s.size() -1] == '1')
            return false;

        queue<int> indexQueue;
        indexQueue.push(0);
        int farthest = 0;

        while (!indexQueue.empty()) {
            int currIndex = indexQueue.front();
            indexQueue.pop();

            if (currIndex == s.size() - 1) return true;

            int start = std::max(currIndex + minJump, farthest + 1);
            int end = std::min(currIndex + maxJump, (int)s.size() - 1);

            for (int j = start; j <= end; ++j) {
                if (s[j] == '0') {
                    indexQueue.push(j);
                }
            }

            farthest = std::max(farthest, currIndex + maxJump);
        }

        return false;
        
    }
};