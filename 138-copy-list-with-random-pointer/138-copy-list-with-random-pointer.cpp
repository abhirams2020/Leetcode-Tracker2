/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> newList;
    
    Node* copyRandomList(Node* head) {
        newList[NULL] = NULL;
        Node* curr = head;
        // create new nodes for every node in prev list
        while(curr){
            newList[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        // copy the next and random nodes of prev list
        curr = head;
        while(curr){
            Node* currNode = newList[curr];
            currNode->next = newList[curr->next];
            currNode->random = newList[curr->random];
            curr = curr->next;
        }
        // return head of new list = newList[prev head node]
        return newList[head];
    }
};