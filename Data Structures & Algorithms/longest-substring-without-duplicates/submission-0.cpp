class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<int> cache (128,-1);                   
        int left = 0;
        int maxLenght = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int charIndex = s[i];

            if (cache[charIndex] >= left) {
                left = cache[charIndex] + 1;
            }

            cache[charIndex] = i;

            maxLenght = max(maxLenght, i - left + 1);

        }
        return maxLenght;
        
    }
};
