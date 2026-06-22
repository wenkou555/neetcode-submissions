class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }

        int required[128] = {0};
        int requiredSize = 0;
        for (auto& it : t) {
            if (required[it] == 0)
                requiredSize++;
            required[it]++;
        }

        int curRequired = 0;

        int left = 0;
        int curWindow[128] = {0};

        int subStrStart = 0;
        int subStrSize = INT_MAX;


        for (int i = 0; i < s.size(); i++) {
            curWindow[s[i]] ++;
            if (curWindow[s[i]] == required[s[i]] && required[s[i]] != 0)
                {
                   curRequired++; 
                }
            if (curRequired == requiredSize) {
                bool isContinue = true;
                while (isContinue) {
                    curWindow[s[left]]--;
                    if (required[s[left]] != 0 and curWindow[s[left]] < required[s[left]]) {
                        curRequired--;
                        if (i - left < subStrSize) {
                            subStrStart = left;
                            subStrSize = i - left + 1;
                        }
                        isContinue = false;
                    }
                    left++;
                }
            }
            
        }

        return subStrSize == INT_MAX ? "" : s.substr(subStrStart, subStrSize);

    }
};
