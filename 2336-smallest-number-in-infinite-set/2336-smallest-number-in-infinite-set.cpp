class SmallestInfiniteSet {
public:
    unordered_set<int> notInSet;
    
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        int i=1;
        while(true){
            if(notInSet.count(i)==0){
                notInSet.insert(i);
                return i;
            }
            i++;
        }
    }
    
    void addBack(int num) {
        if(notInSet.count(num)!=0){
            notInSet.erase(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */