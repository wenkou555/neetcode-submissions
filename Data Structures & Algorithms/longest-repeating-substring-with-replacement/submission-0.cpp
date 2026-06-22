class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int cache [26] = {0};
        int maxFrequency = 0;
        int maxLength = 0;

        for (int i = 0; i < s.size(); i++)  
        {
            cache[s[i] - 'A'] += 1;
            maxFrequency = max(cache[s[i] - 'A'], maxFrequency);
            if (i - left + 1 - maxFrequency > k)
            {
                cache[s[left] - 'A']--;
                left++;
            }
            maxLength = max(maxLength, i - left + 1);

        }

        return maxLength;
        
    }
};
