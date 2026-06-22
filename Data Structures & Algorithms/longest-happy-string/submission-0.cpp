
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Max-heap stores pairs of {count, char}. Automatically sorts by count.
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string result = "";

        while (!pq.empty()) {
            // Get the character we have the most of
            auto [count1, char1] = pq.top();
            pq.pop();

            int n = result.size();
            
            // Check if adding it would create 3 in a row
            if (n >= 2 && result[n-1] == char1 && result[n-2] == char1) {
                // If we don't have a secondary character to break the streak, we must stop.
                if (pq.empty()) {
                    break; 
                }
                
                // Grab the second most frequent character
                auto [count2, char2] = pq.top();
                pq.pop();

                // Use it to break the streak
                result += char2;
                count2--;
                
                // Put both back in the queue if they still have counts remaining
                if (count2 > 0) pq.push({count2, char2});
                pq.push({count1, char1}); // We didn't use char1 this turn
                
            } else {
                // It's safe to use our most frequent character
                result += char1;
                count1--;
                if (count1 > 0) pq.push({count1, char1});
            }
        }

        return result;
    }
};