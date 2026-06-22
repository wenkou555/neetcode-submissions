class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        
        // Pre-allocate the exact maximum size we could possibly need
        int maxLen = max(a.size(), b.size());
        string res(maxLen, '0'); // Fill it with '0's initially
        int k = maxLen - 1;      // Pointer for our result string
        
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            
            // If we run out of space in our pre-allocated string (because of a final carry)
            // we just insert the '1' at the very front.
            if (k >= 0) {
                res[k--] = (sum % 2) + '0';
            } else {
                res.insert(res.begin(), '1');
            }
            
            carry = sum / 2;
        }
        
        return res;
    }
};