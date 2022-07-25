class MinStack {
public:
    stack<int> st;
    stack<int> minVal;
    
    MinStack() {
        
    }
    
    void push(int val) {
        cout<<"Push : "<<val<<"\n";
        st.push(val);
        if(minVal.empty() || val <= minVal.top()){
            minVal.push(val);
        }
    }
    
    void pop() {
        cout<<"Pop : "<<st.top()<<"\n";
        if(!minVal.empty() && minVal.top() == st.top()){
            minVal.pop();
        }
        st.pop();
    }
    
    int top() {
        cout<<"Top : "<<st.top()<<"\n";
        return st.top();
    }
    
    int getMin() {
        cout<<"Min : "<<minVal.top()<<"\n";
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