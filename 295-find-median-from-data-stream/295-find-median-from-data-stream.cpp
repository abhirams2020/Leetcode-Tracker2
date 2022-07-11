class MedianFinder {
public:
    // small has elements less than or equal to large and sorted in descending order
    priority_queue<int> small;
    // large has elements greater than or equal to small and sorted in ascending order
    priority_queue<int,vector<int>,greater<>> large;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // IMPORTANT STEP
        // If number < biggest in small, it belongs to small, else it belongs to large
        // Small should always have values >= large
        if(small.empty() || num<small.top()){
            small.push(num);
        }
        else {
            large.push(num);
        }
        
        // make the sizes of both priority queues similar by popping elements from one queue and pushing to other
        // if small queue is bigger, choose largest elements from small queue and push to large queue
        while(!small.empty() && small.size() > large.size()+1){
            large.push(small.top());
            small.pop();
        }
        // if large queue is bigger, choose smallest elements from large queue and push to small queue
        while(!large.empty() && large.size() > small.size()+1){
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        // if both are empty, no median exist. so return 0
        if(small.empty() && large.empty()){
            return 0;
        }
        // is small is greater, means small size = large size + 1. So median is in small. Return largest in small.
        else if(small.size() > large.size()){
            return small.top();
        }
        // is large is greater, means large size = small size + 1. So median is in large. Return smallest in large.
        else if(large.size() > small.size()){
            return large.top();
        }
        // if both are same size, take average of largest in small and smallest in large
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