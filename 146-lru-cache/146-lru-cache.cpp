// USING STL
class LRUCache {
private:
    int size;
    // mp stores key and address of that key in list
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    // list acts as key,value pair. front is most recent.
    list<pair<int,int>> li;
public:
    // when an element in list is accessed, call used fn to move it to front
    void moveToFront(int key, int value){
        li.erase(mp[key]);
        li.push_front({key,value});
        mp[key] = li.begin();
    }
    
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(mp.count(key)){
            // if mp contains key, update the list and return mp value
            moveToFront(key,mp[key]->second);
            return mp[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            // if key found in mp, update the list and mp value
            moveToFront(key,value);
        }
        else {
            if(size == mp.size()){
                // if list is full, remove least recently used element
                mp.erase(li.back().first);
                li.pop_back();
            }
            li.push_front({key,value});
            // begin() - address of front element
            // front() - value of front element
            mp[key] = li.begin();
        }
    }
};

/*
// USING DOUBLY LINKED LIST
class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int key, int val){
            this->key = key;
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
    };
    
    int size;
    unordered_map<int,Node*> mp;
    // front->next and back->prev gives front and back elements in list
    Node* front = new Node(0,0);
    Node* back = new Node(0,0);
    
    LRUCache(int capacity) {
        size = capacity;
        front->next = back;
        back->prev = front;
    }
    
    void moveToFront(Node* curr){
        curr->next = front->next;
        front->next->prev = curr;
        curr->prev = front;
        front->next = curr;
        mp[curr->key] = curr;
    }
    
    void removeNode(Node* curr) {
        mp.erase(curr->key);
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }
    
    int get(int key) {
        if(mp.count(key)){
            Node* curr = mp[key];
            removeNode(curr);
            moveToFront(curr);
            return curr->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            removeNode(mp[key]);
        }
        else if(mp.size() == size){
            // remove least recently used element
            removeNode(back->prev);
        }
        Node* curr = new Node(key,value);
        moveToFront(curr);
    }
};
*/


/*
Algorithm Outline:

LRUCache()
1. key -> (addr, value)
2. List, will contain keys
3. cap=capacity

Get
1. if found, movetofirst for key, return. Else -1

Put
1. if exist, update.
2. else add
3. move to first
4. if >capacity, remove last in list i.e. LRU

Move to first
1. erase element
2. add to first
3. store first addr in ht
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */