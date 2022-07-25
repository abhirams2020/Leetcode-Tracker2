class MinStack {
public:
    stack<int> st;
    stack<int> minVal;
    
    MinStack() {
        
    }
    
    // push element to min stack when curr val <= curr min
    void push(int val) {
        st.push(val);
        if(minVal.empty() || val <= minVal.top()){
            minVal.push(val);
        }
    }

    // pop element from min stack when stack top value == curr min value
    void pop() {
        if(!minVal.empty() && minVal.top() == st.top()){
            minVal.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minVal.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */