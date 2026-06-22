class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> subStrVectorContainer = {};
        vector<string> subStrVector = {};
        findPalindrome(s, 0, subStrVector, subStrVectorContainer);
        return subStrVectorContainer;
        
    }

private:
    void findPalindrome(string& s, int start, vector<string>& subStrVector, vector<vector<string>>& subStrVectorContainer) {
        if (start == s.length()) {
            subStrVectorContainer.push_back(subStrVector);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                subStrVector.push_back(s.substr(start, i - start + 1));
                findPalindrome(s, i + 1, subStrVector, subStrVectorContainer);
                subStrVector.pop_back();
            }
        }
    }


    bool isPalindrome(string& s, int start, int end) {
        if (start == end) 
            return true;

        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
};
