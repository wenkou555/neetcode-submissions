#include <array>
#include <string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        
        // 1. Use std::array. It's fast (stack) and supports '==' comparison.
        std::array<int, 26> s1Signature = {0};
        std::array<int, 26> windowSignature = {0};
        
        // Initialize signatures with the first window
        for (int i = 0; i < s1.size(); i++) {
            s1Signature[s1[i] - 'a']++;
            windowSignature[s2[i] - 'a']++;
        }
        
        // Check the very first window
        if (s1Signature == windowSignature) return true;
        
        // 2. Slide the window
        int left = 0;
        // Start right from s1.size() since we already filled the first window
        for (int right = s1.size(); right < s2.size(); right++) {
            // Add new character (expand right)
            windowSignature[s2[right] - 'a']++;
            
            // Remove old character (shrink left)
            windowSignature[s2[left] - 'a']--;
            left++;
            
            // 3. Compare entire array in one line (O(26) -> O(1) constant time)
            if (s1Signature == windowSignature) return true;
        }
        
        return false;
    }
};