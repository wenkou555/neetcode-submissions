class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        if (words.empty())
            return "";

        if (words.size() == 1) {
            return words[0];
        }

        unordered_map<char, unordered_set<char>> adjacentMap;
        unordered_map<char, int> prerequisiteMap;

        if (not dependencyMapBuilder(words, adjacentMap, prerequisiteMap))
            return "";

        queue<char> charQueue;
        string resultAlphabet = "";

        for (const auto& [letter, inDegree] : prerequisiteMap) {
            if (inDegree == 0) {
                charQueue.push(letter);
            }
        }

        while (!charQueue.empty()) {
            char curChar = charQueue.front();
            charQueue.pop();
            
            // Add to our final alphabet!
            resultAlphabet += curChar;

            // Destroy the outgoing arrows to its neighbors
            for (char neighbor : adjacentMap[curChar]) {
                prerequisiteMap[neighbor]--;
                
                // If a neighbor is now free, push it to the queue!
                if (prerequisiteMap[neighbor] == 0) {
                    charQueue.push(neighbor);
                }
            }
        }

        if (resultAlphabet.size() != prerequisiteMap.size()) {
            return ""; // There was a circular dependency!
        }

        return resultAlphabet;
    }

private:
    bool dependencyMapBuilder(vector<string>& words, 
                              unordered_map<char, unordered_set<char>>& adjacentMap, 
                              unordered_map<char, int>& prerequisiteMap) {
        for (string word : words) {
            for (char c : word) {
                prerequisiteMap[c] = 0;
            }
        }
        
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            bool found = false;
            int k = 0;

            while (k < word1.size() && k < word2.size()) {
                char char1 = word1[k];
                char char2 = word2[k];
                if (char1 != char2) {
                    if (adjacentMap[char1].find(char2) == adjacentMap[char1].end()) {
                        adjacentMap[char1].insert(char2);
                        prerequisiteMap[char2]++;
                    }
                    found = true;
                    break;
                }

                k++;
            }

            if (not found && word1.length() > word2.length()) {
                return false;
            }
        }

        return true;

    }
};
