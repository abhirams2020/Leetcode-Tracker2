class Solution {
public:
    int countChar(string &str, char ch){
        int count = 0;
        for(auto c:str){
            if(c==ch){
                count++;
            }
        }
        return count;
    }
    
    bool canChange(string start, string target) {
        if(start.length() != target.length()){
            return false;
        }
        
        if(countChar(start,'L')!=countChar(target,'L') || countChar(start,'R')!=countChar(target,'R')){
            return false;
        }
        
        vector<int> s;
        vector<int> t;
        
        // remove spaces from start and target and store the positions
        for(int i=0;i<start.length();i++){
            if(start[i]!='_')
                s.push_back(i);
            if(target[i]!='_')
                t.push_back(i);
        }
        
        for(int i=0;i<s.size();i++){
            if(start[s[i]]!=target[t[i]]){
                return false;
            }
            if(start[s[i]]=='L' && s[i]<t[i]){
                return false;
            }
            if(start[s[i]]=='R' && s[i]>t[i]){
                return false;
            }
        }
        
        return true;
    }
};