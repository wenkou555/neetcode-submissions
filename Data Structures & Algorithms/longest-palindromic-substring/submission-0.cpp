class Solution {
public:
    string longestPalindrome(string s) {
        int strLen = s.size();
        if (strLen == 0)
            return "";
        
        if (strLen == 1)
            return s;

        int maxLen = 0;
        int start = 0;

        for (int i = 0; i < strLen; i++) {
            int palLen = max(expand(s, i, i),
                             expand(s, i + 1, i));

            if (palLen > maxLen) {
                maxLen = palLen;
                start = i - (maxLen - 1)/2;
            }

        }

        return s.substr(start, maxLen);
        
    }

private:
    int expand(string& s, int left, int right) {
        // While in bounds AND characters match...
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return length (math trick: right - left - 1)
        return right - left - 1;
    }
};
