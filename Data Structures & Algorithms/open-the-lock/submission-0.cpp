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
        unordered_set<string> visited;
        for (const auto& deadend: deadends) {
            visited.insert(deadend);
        }

        if (visited.count("0000"))
            return -1; 

        int moveCount = 0;

        queue<string> combinations;
        combinations.push("0000");
        visited.insert("0000");

        while (!combinations.empty()) {
            int queueSize = combinations.size();
            for (int i = 0; i < queueSize; ++i) {
                string combination = combinations.front();
                combinations.pop();

                if (combination == target) 
                    return moveCount;

                for (int j = 0; j < 4; ++j) {
                    string up = combination;
                    string down = combination;

                    up[j] = turnUp(combination[j]);
                    down[j] = turnDown(combination[j]);

                    if (!visited.count(up)) {
                        combinations.push(up);
                        visited.insert(up);
                    }

                    if (!visited.count(down)) {
                        combinations.push(down);
                        visited.insert(down);
                    }

                }    
            }
            ++moveCount;
        }
        return -1;
    }
};