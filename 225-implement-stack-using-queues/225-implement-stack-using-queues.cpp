/*
// USING 2 QUEUES
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
*/

// USING 1 QUEUE AND MAKING PUSH O(N)
class MyStack {
public:
    queue<int> q;
    
    MyStack() {
        
    }
    
    void push(int x) {
        // we need to add x to front of queue
        // so add x to back and move the front elements to back of queue
        int n = q.size();
        q.push(x);
        while(n--){
            int curr = q.front();
            q.push(curr);
            q.pop();
        }
    }
    
    int pop() {
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        return q.front();       
    }
    
    bool empty() {
        return q.empty();
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