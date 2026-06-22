class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; // Our "Stack"
        
        for (int ast : asteroids) {
            bool destroyed = false;
            
            // WE HAVE A COLLISION! 
            // (Stack is not empty, top is moving right (+), new rock is moving left (-))
            while (!st.empty() && st.back() > 0 && ast < 0) {
                
                // Case 1: Stack rock is smaller. Destroy the stack rock and keep going!
                if (st.back() < abs(ast)) {
                    st.pop_back();
                    continue; 
                }
                // Case 2: Both rocks are the same size. Mutual Destruction!
                else if (st.back() == abs(ast)) {
                    st.pop_back();
                }
                
                // If we hit Case 2 or the Stack rock was bigger, our new asteroid is dead.
                destroyed = true;
                break; 
            }
            
            // If our new asteroid survived the gauntlet, push it to the stack
            if (!destroyed) {
                st.push_back(ast);
            }
        }
        
        return st;
    }
};