class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            // skip non-alphanumeric on both sides
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;

            // compare (case-insensitive)
            if (tolower(s[i]) != tolower(s[j])) return false;

            i++;
            j--;
        }

        return true;
    }
};
