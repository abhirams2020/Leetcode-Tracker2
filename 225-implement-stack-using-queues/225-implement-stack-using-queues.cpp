class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        // pop last added in stack. ie last in queue
        // so remove all elements of q till we have only 1 element remaining
        while(q1.size()>1){
            int curr = q1.front();
            q2.push(curr);
            q1.pop();
        }
        int ans = q1.front();
        q1.pop();
        while(!q2.empty()){
            int curr = q2.front();
            q1.push(curr);
            q2.pop();
        }
        return ans;
    }
    
    int top() {
         // top is last added in stack. ie last in queue
        // so remove all elements of q till we have only 1 element remaining
        while(q1.size()>1){
            int curr = q1.front();
            q2.push(curr);
            q1.pop();
        }
        int ans = q1.front();
        q2.push(ans);
        q1.pop();
        while(!q2.empty()){
            int curr = q2.front();
            q1.push(curr);
            q2.pop();
        }
        return ans;       
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */