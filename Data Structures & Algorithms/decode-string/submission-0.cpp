class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        
        string current_string = "";
        int current_num = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                // Handle multi-digit numbers (e.g., "12")
                current_num = current_num * 10 + (c - '0');
            } 
            else if (c == '[') {
                // Save current state before going deeper
                numStack.push(current_num);
                strStack.push(current_string);
                
                // Reset for the new bracket level
                current_num = 0;
                current_string = "";
            } 
            else if (c == ']') {
                // Unpack the previous state
                int k = numStack.top();
                numStack.pop();
                
                string prev_string = strStack.top();
                strStack.pop();
                
                // Multiply current_string by k and append to prev_string
                string repeated_chunk = "";
                for (int i = 0; i < k; i++) {
                    repeated_chunk += current_string;
                }
                
                current_string = prev_string + repeated_chunk;
            } 
            else {
                // It's just a regular letter
                current_string += c;
            }
        }
        
        return current_string;
    }
};