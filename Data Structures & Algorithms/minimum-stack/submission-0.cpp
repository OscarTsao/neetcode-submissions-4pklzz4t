class MinStack {
private:
    long int min;
    std::stack<long int> stack;

public:
    MinStack() {
    }
    
    void push(int val) {
        if (stack.empty()){
            stack.push(0);
            min = val;
        }
        else{
            stack.push(val - min);
            if (val < min) min = val;
        }
    }
    
    void pop() {
        if (stack.empty()) return;
        long int pop = stack.top();
        stack.pop();
        if (pop < 0) min = min - pop;
    }
    
    int top() {
        long top = stack.top();
        return (top > 0) ? (top+min) : (int)min;
    }
    
    int getMin() {
        return (int)min;
    }
};
