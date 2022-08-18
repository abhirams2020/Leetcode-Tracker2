/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> copyMap;
    
    unordered_set<Node*> visited;
    
    void dfs(Node* curr){
        if(curr==NULL){
            return;
        }
        visited.insert(curr);
        Node* currCopy = new Node(curr->val);
        copyMap[curr] = currCopy;
        
        for(auto child:curr->neighbors){
            // if child not copied yet, call dfs with child as source and copy all its neighbours
            if(visited.count(child)==0){
                dfs(child);
            }
            currCopy->neighbors.push_back(copyMap[child]);
        }
    }
    
    Node* cloneGraph(Node* node) {
        dfs(node);
        return copyMap[node];
    }
};