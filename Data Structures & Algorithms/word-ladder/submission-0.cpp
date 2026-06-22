class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> wordQueue;
        wordQueue.push(beginWord);
        
        int iterationCounter = 1;
        while (!wordQueue.empty()) {
            int wordQueueSize = wordQueue.size();
            for (int i = 0; i < wordQueueSize; i++) {
                string curWord = wordQueue.front();
                wordQueue.pop();

                if (curWord == endWord)
                    return iterationCounter;

                string tempWord = curWord;
                for (int j = 0; j < tempWord.size(); j ++) {
                    char originalChar = tempWord[j];
                    for (int k = 0; k < 26; k ++) {
                        if ('a' + k == originalChar) 
                            continue;
                            
                        tempWord[j] = 'a' + k;

                        if (wordSet.count(tempWord) == 0)
                            continue;

                        wordQueue.push(tempWord);
                        wordSet.erase(tempWord);
                    }
                    tempWord[j] = originalChar;
                }
            }

            iterationCounter++;
        }

        return 0;
    }
};
