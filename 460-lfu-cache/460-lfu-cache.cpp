class LFUCache {
public:
    using pii = pair<int,int>;
    
    int capacity;
    int currCapacity;
    
    map<int, list<pii>> freqList;
    unordered_map<int, list<pii>::iterator> keyPtr;
    unordered_map<int, int> keyFreq;
    
    LFUCache(int capacity) {
        currCapacity = 0;
        this->capacity = capacity;
    }
    
    // function to update existing key with new value in LFU cache
    void updateKey(int key, int value){
        int currFreq = keyFreq[key];
        auto keyAddr = keyPtr[key];
        // erase curr key from the LFU cache and add to updated frequency list
        freqList[currFreq].erase(keyAddr);
        currCapacity--;
        // add key,value pair to new freq = currFreq + 1
        addKey(key,value,currFreq+1);
        // remove the prev freq from map if its list is empty
        if(freqList[currFreq].empty()){
            freqList.erase(currFreq);
        }
    }
    
    // function to remove the least frequent element from LFU cache
    void removeLeastFrequent(){
        if(freqList.empty()){
            return;
        }
        // find the list of least frequent elements. from that list remove the least recent element
        int leastFreq = freqList.begin()->first;
        // least recent element will be at end of freqList[leastFreq]
        pii leastRecent = freqList[leastFreq].back();
        int leastRecentKey = leastRecent.first; // key of least recent element in list of least freq
        freqList[leastFreq].pop_back(); // remove the least recent element from least freq list
        keyPtr.erase(leastRecentKey); // remove deleted key from keyPtr and keyFreq
        keyFreq.erase(leastRecentKey);
        if(freqList[leastFreq].size()==0){
            freqList.erase(leastFreq);
        }
        currCapacity--;
    }
    
    // function to add new key, value pair in the LFU cache
    void addKey(int key,int value,int freq){
        // if no elements can be added to lfu cache, return
        if(capacity==0){
            return;
        }
        // if element can be added, remove the old elements till we have space for new
        if(currCapacity >= capacity){
            removeLeastFrequent();
        }
        // add {key,value} to given freq list and update address and frequency of key
        freqList[freq].push_front({key,value});
        keyPtr[key] = freqList[freq].begin();
        keyFreq[key] = freq;
        currCapacity++;
    }
    
    // function to print the current LFU
    void printLFU(){
        cout<<"LRU \n";
        for(auto [k,li]:freqList){
            cout<<k<<" : ";
            for(auto i:li){
                cout<<i.first<<","<<i.second<<" ";
            }
            cout<<"\n";
        }
    }
    
    int get(int key) {
        if(keyPtr.count(key)){
            int val = keyPtr[key]->second;
            updateKey(key,val);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(keyPtr.count(key)){
            updateKey(key,value);
        }
        else {
            addKey(key,value,0);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */