class Solution {
private:
    char turnUp(char ch) {
        return (ch == '9') ? '0' : ch + 1;
    }   

    char turnDown(char ch) {
        return (ch == '0') ? '9' : ch - 1;
    }

public:
    int openLock(vector<string>& deadends, string target) {
        // 1. O(1) Hash Set initialized instantly
        unordered_set<string> visited(deadends.begin(), deadends.end());

        string start = "0000";
        if (visited.count(start)) return -1;
        if (start == target) return 0;

        // In Bi-directional BFS, queues are replaced by Hash Sets 
        // so we can do O(1) intersection checks!
        unordered_set<string> beginSet{start};
        unordered_set<string> endSet{target};

        int moves = 0;

        while (!beginSet.empty() && !endSet.empty()) {
            // ALWAYS expand the smaller wave to minimize branching
            if (beginSet.size() > endSet.size()) {
                std::swap(beginSet, endSet);
            }

            unordered_set<string> nextWave;

            for (string curr : beginSet) {
                for (int j = 0; j < 4; ++j) {
                    char cache = curr[j];

                    // Test both directions using an initializer list
                    for (char nextChar : {turnUp(cache), turnDown(cache)}) {
                        curr[j] = nextChar;

                        // Did our wave just collide with the opposite wave?!
                        if (endSet.count(curr)) {
                            return moves + 1;
                        }

                        if (!visited.count(curr)) {
                            visited.insert(curr);
                            nextWave.insert(curr);
                        }
                    }
                    curr[j] = cache; // Backtrack
                }
            }

            beginSet = std::move(nextWave);
            moves++;
        }

        return -1;
    }
};