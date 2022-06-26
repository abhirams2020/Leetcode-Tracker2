class FreqStack {
public:
    int maxFreq = 0;
    // freq stores frequency of each element present in data structure
    unordered_map<int,int> freq;
    // freqMap stores elements with each frequency in the order they were added
    unordered_map<int,stack<int>> freqMap;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        int prev_count = 0;
        if(freq.count(val)){
            prev_count = freq[val];
        }
        maxFreq = max(maxFreq, prev_count + 1);
        freqMap[prev_count+1].push(val);
        freq[val]++;
    }
    
    int pop() {
        int top = freqMap[maxFreq].top();
        // remove top element. if top element was last with maxFreq, reduce maxFreq.
        freqMap[maxFreq].pop();
        if(freqMap[maxFreq].empty()){
            freqMap.erase(maxFreq);
            maxFreq--;
        }
        // reduce frequency of top element. If frequency become 0, remove top.
        freq[top]--;
        if(freq[top]==0){
            freq.erase(top);
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