class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> substrTracker(n + 1, false);
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        substrTracker[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (substrTracker[j] && wordSet.count(s.substr(j, i-j))) {
                    substrTracker[i] = true;
                    break;
                }
            }

        }

        return substrTracker[n];

        
    }
};
