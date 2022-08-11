// USING DICTIONARY TO STORE NEXT CHARACTERS AND ITS NODE
class TrieNode {
public:
    bool is_word;
    // map stores next node of current characters
    vector<TrieNode*> children;
    TrieNode() {
        is_word = false;
        children.resize(26,NULL);
    }
};

class WordDictionary {
private:
    TrieNode* root;
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* curr = root;
        for(auto &ch:word){
            if(curr->children[ch-'a'] == NULL){
                curr->children[ch-'a'] = new TrieNode();
            }
            curr = curr->children[ch-'a'];
        }
        curr->is_word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchTrie(word,0,root);
    }
    
    // function to check if word from index i is present in trie starting at curr
    bool searchTrie(string &word, int index, TrieNode* curr) {
        for (int i = index; i<word.length() ; i++) {
            if (word[i] == '.'){
                // if word[i]=='.', do dfs on all the children with word.substr(i+1)
                // if any dfs returns true, there exist a word. Return true
                for (auto &childNode:curr->children) {
                    if (childNode!=NULL && searchTrie(word, i + 1, childNode)) {
                        return true;
                    }
                }
                return false;
            }
            
            if(curr->children[word[i]-'a'] == NULL){
                return false;
            }
            curr = curr->children[word[i]-'a'];
        }
        return curr->is_word;
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */