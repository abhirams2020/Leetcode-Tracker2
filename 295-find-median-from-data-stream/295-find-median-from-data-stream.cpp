class MedianFinder {
public:
    // small has elements less than or equal to large and sorted in descending order
    priority_queue<int> small;
    // large has elements greater than or equal to small and sorted in ascending order
    priority_queue<int,vector<int>,greater<>> large;
    
    MedianFinder() {
        
    }
    
    void printLarge(){
        vector<int> temp;
        cout<<"LARGE : ";
        while(!large.empty()){
            cout<<large.top()<<" ";
            temp.push_back(large.top());
            large.pop();
        }
        cout<<"\n";
        for(auto i:temp){
            large.push(i);
        }
    }
    
    void printSmall(){
        vector<int> temp;
        cout<<"SMALL : ";
        while(!small.empty()){
            cout<<small.top()<<" ";
            temp.push_back(small.top());
            small.pop();
        }
        cout<<"\n";
        for(auto i:temp){
            small.push(i);
        }        
    }
    
    void addNum(int num) {
        if(small.empty() || num<small.top()){
            small.push(num);
        }
        else {
            large.push(num);
        }
        while(!small.empty() && small.size() > large.size()+1){
            large.push(small.top());
            small.pop();
        }
        while(!large.empty() && large.size() > small.size()+1){
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
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
            return (double)(large.top() + small.top())/2.0l;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */