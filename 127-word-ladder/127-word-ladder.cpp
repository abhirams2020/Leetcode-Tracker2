class Solution {
public:
    using psi = pair<string,int>;
    unordered_map<string, vector<string>> adj;
    
    // map a node to its neighbours
    // for hot its neighbours can be in keys #ot, h#t, ho#
    // so while adding words from word list to adjacency list, make each character of the word unknown and add to map
    void createGraph(int n, vector<string> &wordList){
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
        int n = endWord.length();
        
        createGraph(n, wordList);
        
        queue <psi> q;
        q.push({beginWord,1});
        
        unordered_set<string> visited;
        visited.insert(beginWord);
        
        while(!q.empty()){
            string currWord = q.front().first;
            int currCount = q.front().second;
            q.pop();
            
            if(currWord == endWord){
                return currCount;
            }
            
            string temp = currWord;
            
            // to add children of currWord to queue, 1 character of currWord should be made unknown
            // mp[temp] will give words with similar format. add all such nodes to queue except currWord
            // add word to visited array after it is visited to avoid cycle
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