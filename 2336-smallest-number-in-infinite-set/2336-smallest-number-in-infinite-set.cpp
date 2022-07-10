class SmallestInfiniteSet {
public:
    // add elements removed from infinite set to notInfSet
    unordered_set<int> notInfSet;
    
    SmallestInfiniteSet() {
        
    }
    
    // smallest element in infinite set is smallest no from 1 which is not in notInfSet. after finding smallest, add to notInfSet
    int popSmallest() {
        int i=1;
        while(true){
            if(notInfSet.count(i)==0){
                notInfSet.insert(i);
                return i;
            }
            i++;
        }
    }
    
    // when element is added back to set, if element is in notInfSet remove it.
    void addBack(int num) {
        if(notInfSet.count(num)!=0){
            notInfSet.erase(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */