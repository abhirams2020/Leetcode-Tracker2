class FreqStack {
public:
    int maxCount = 0;
    unordered_map<int,int> counter;
    unordered_map<int, stack<int>>  mp;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        int prev_count = 0;
        if(counter.count(val)){
            prev_count = counter[val];
        }
        maxCount = max(maxCount, prev_count + 1);
        counter[val]++;
        mp[prev_count+1].push(val);
    }
    
    int pop() {
        int top = mp[maxCount].top();
        mp[maxCount].pop();
        if(mp[maxCount].empty()){
            mp.erase(maxCount);
            maxCount--;
        }
        counter[top]--;
        if(counter[top]==0){
            counter.erase(top);
        }
        return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */