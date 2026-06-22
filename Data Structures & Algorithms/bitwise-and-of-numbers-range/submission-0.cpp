class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int chops = 0;
        
        // Keep chopping off the rightmost bits until the numbers match
        while (left < right) {
            left >>= 1;
            right >>= 1;
            chops++;
        }
        
        // We found the common prefix! Now pad it with the zeros we chopped off
        return left << chops;
    }
};