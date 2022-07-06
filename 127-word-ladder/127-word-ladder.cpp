class Solution {
public:
    using psi = pair<string,int>;
    unordered_map<string, vector<string>> adj;
    
    // map a node to its neighbours
    // for hot its neighbours can be in keys #ot, h#t, ho#
    // so while adding words from word list to adjacency list, make each character of the word unknown and add to map
    void createMapping(int n, vector<string> &wordList){
        for(auto str:wordList){
            string temp = str;
            for(int i=0;i<n;i++){
                temp[i] = '#';
                adj[temp].push_back(str);
                temp[i] = str[i];
            }
        }
    }
    
    // Check if end word present in word list
    bool checkEndWord(string &endWord, vector<string> &wordList){
        for(auto str:wordList){
            if(str==endWord){
                return true;
            }
        }
        return false;
    }
    
    int ladderLength(string &beginWord, string endWord, vector<string>& wordList) {
        if(checkEndWord(endWord, wordList) == false){
            return false;
        }
        string curr = beginWord;
        int n = endWord.length();
        
        createMapping(n, wordList);
        
        queue <psi> q;
        q.push({curr,1});
        
        unordered_set<string> visited;
        visited.insert(curr);
        
        while(!q.empty()){
            string currWord = q.front().first;
            int currCount = q.front().second;
            q.pop();
            
            if(currWord == endWord){
                return currCount;
            }
            
            string temp = currWord;
            
            for(int i=0;i<n;i++){
                temp[i] = '#';
                for(auto str:adj[temp]){
                    if(visited.count(str)==0){
                        q.push({str,currCount+1});
                        visited.insert(str);
                    }
                }
                temp[i] = currWord[i];
            }
        }
        return 0;
    }
};