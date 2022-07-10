class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<>> pq;
    unordered_set<int> s;
    
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        int i=1;
        while(true){
            if(s.count(i)==0){
                s.insert(i);
                return i;
            }
            i++;
        }
    }
    
    void addBack(int num) {
        if(s.count(num)!=0){
            s.erase(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */