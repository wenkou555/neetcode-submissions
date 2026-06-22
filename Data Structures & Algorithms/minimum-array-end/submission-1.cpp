class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x;      // Start with x as our foundation
        long long remaining = n - 1; // The number we need to weave into the 0s
        long long position = 1;      // To scan through the bits of x
        
        // While we still have bits of (n-1) left to place...
        while (remaining > 0) {
            
            // If the current bit of x is a 0, it's an empty slot!
            if ((x & position) == 0) {
                
                // If the lowest bit of our remaining number is a 1, drop it in
                if (remaining & 1) {
                    result |= position; 
                }
                
                // Shift our remaining number to get the next bit ready
                remaining >>= 1;
            }
            
            // Move our scanner to the next bit position in x
            position <<= 1;
        }
        
        return result;
    }
};