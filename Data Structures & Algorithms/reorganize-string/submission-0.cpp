class Solution {
public:
    string reorganizeString(string s) {
        // 1. Count the frequencies
        vector<int> counts(26, 0);
        for (char c : s) {
            counts[c - 'a']++;
        }
        
        // 2. Build the Max Heap
        // Pushing pairs of {frequency, character}
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++) {
            if (counts[i] > 0) {
                pq.push({counts[i], i + 'a'});
            }
        }
        
        string res = "";
        // 3. The Waitlist (Cooldown)
        // Starts empty with a dummy character
        pair<int, char> prev = {0, '#'}; 
        
        // 4. Process the Queue
        while (!pq.empty()) {
            // Grab the most frequent available character
            auto current = pq.top();
            pq.pop();
            
            // Add it to our result string and decrement its count
            res += current.second;
            current.first--;
            
            // If the character from the PREVIOUS loop still has remaining counts,
            // its cooldown is over! Push it back into the heap.
            if (prev.first > 0) {
                pq.push(prev);
            }
            
            // Put the character we just used on the waitlist
            // so it physically cannot be picked in the next immediate loop.
            prev = current;
        }
        
        // 5. The Impossible Check
        // If we emptied the heap but the string isn't finished, 
        // it means a character got permanently stuck on the waitlist.
        if (res.length() != s.length()) {
            return "";
        }
        
        return res;
    }
};