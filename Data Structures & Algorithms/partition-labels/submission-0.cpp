class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastCharIndex(26, -1);
        for (int i = 0; i < s.size(); i++) {
            lastCharIndex[s[i]-'a'] = i;
        }

        int startIndex = 0;
        int endIndex = 0;
        vector<int> substrSize;

        for (int i = 0; i < s.size(); i++) {
            endIndex = max(endIndex, lastCharIndex[s[i]-'a']);
            if (i == endIndex) {
                substrSize.push_back(endIndex - startIndex + 1);
                startIndex = i + 1;
            }
        }

        return substrSize;
    }
};
