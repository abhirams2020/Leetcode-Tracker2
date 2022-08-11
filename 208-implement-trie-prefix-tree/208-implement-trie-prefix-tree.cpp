class TrieNode {
public:
    bool isWord;
    unordered_map<char,TrieNode*> children;
    TrieNode() {
        isWord = false;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(auto ch:word){
            if(curr->children.count(ch)==0){
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }
        curr->isWord = true;
    }
    
    // if any letter in word is not found, return false
    // if all letters found and end letter has isword = true, return true
    bool search(string word) {
        TrieNode* curr = root;
        for(int i=0;i<word.length();i++){
            if(curr->children.count(word[i])==0){
                return false;
            }
            curr = curr->children[word[i]];
        }
        return curr->isWord == true;
    }
    
    // only difference with search is that even if end is not having isword=true, we return true
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i=0;i<prefix.length();i++){
            if(curr->children.count(prefix[i])==0){
                return false;
            }
            curr = curr->children[prefix[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */