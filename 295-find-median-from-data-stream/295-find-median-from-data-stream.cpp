class MedianFinder {
public:
    // small has elements less than or equal to large and sorted in descending order
    // large has elements greater than or equal to small and sorted in ascending order
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<>> large;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // IMPORTANT STEP
        // If number < biggest in small, it belongs to small, else it belongs to large
        // Small should always have values >= large
        
        // This condition used when data in descending order
        if(small.empty() || num<small.top()){
            small.push(num);
            // make sizes of priority queues similar (size diff < 1) by popping elements from one and pushing to other
            // the heap in which num was pushed should always have bigger size since new median is biased towards it.
            
            // if small queue is bigger than large by more than 1, make the sizes similar by pop from small and push to large
            while(!small.empty() && small.size() > large.size() + 1){
                large.push(small.top());
                small.pop();
            }
        }
        // This condition used when data in ascending order
        else {
            large.push(num);
            // if large queue is bigger than small by more than 1, make the sizes similar by pop from large and push to small
            while(!large.empty() && large.size() > small.size() + 1){
                small.push(large.top());
                large.pop();
            }
        }
    }
    
    double findMedian() {
        // if both are empty, no median exist. so return 0
        // if small is greater, means small size = large size + 1. So median is in small. Return largest in small.
        // if large is greater, means large size = small size + 1. So median is in large. Return smallest in large.
        // if both are same size, take average of largest in small and smallest in large
        if(small.empty() && large.empty()){
            return 0;
        }
        if(small.size() > large.size()){
            return small.top();
        }
        else if(large.size() > small.size()){
            return large.top();
        }
        else {
            return (double)(small.top() + large.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */