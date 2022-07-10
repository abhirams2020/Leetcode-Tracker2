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
        vector<int> s;
        vector<int> t;
        
        // remove spaces from start and target and store the positions
        for(int i=0;i<start.length();i++){
            if(start[i]!='_')
                s.push_back(i);
        }
        for(int i=0;i<target.length();i++){
            if(target[i]!='_')
                t.push_back(i);
        }
        
        if(s.size()!=t.size()){
            return false;
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