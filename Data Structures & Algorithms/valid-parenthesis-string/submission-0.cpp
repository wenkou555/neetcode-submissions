class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openStack;
        stack<int> wildStack;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                openStack.push(i);
            if (s[i] == '*')
                wildStack.push(i);
            
            if (s[i] == ')') {
                if (not openStack.empty())
                    openStack.pop();
                else if (not wildStack.empty())
                    wildStack.pop();
                else
                    return false;
            }
        }

        while (not openStack.empty() and not wildStack.empty()) {
            if (openStack.top() > wildStack.top()) {
                return false;
            }
            openStack.pop();
            wildStack.pop();
        } 

        if (not openStack.empty())
            return false;
            
        return true;
        
    }
};
