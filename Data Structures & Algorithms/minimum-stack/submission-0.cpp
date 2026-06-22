class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        if (internalStack.empty())
            internalStack.push(std::make_pair(val,val));
        else {
            
            internalStack.push(std::make_pair(val, min(val, internalStack.top().second)));
        }
        
    }
    
    void pop() {
        internalStack.pop();
    }
    
    int top() {
         return internalStack.top().first;
    }
    
    int getMin() {
         return internalStack.top().second;
    }

private:
    std::stack<std::pair<int, int>> internalStack;
};
