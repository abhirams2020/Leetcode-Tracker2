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
        
        vector<pair<char,int>> s;
        vector<pair<char,int>> t;
        for(int i=0;i<start.length();i++){
            if(start[i]!='_')
                s.push_back({start[i],i});
            if(target[i]!='_')
                t.push_back({target[i],i});
        }
        
        for(int i=0;i<s.size();i++){
            auto it1 = s[i];
            auto it2 = t[i];
            if(it1.first!=it2.first){
                return false;
            }
            if(it1.first=='L' && it1.second<it2.second){
                return false;
            }
            if(it1.first=='R' && it1.second>it2.second){
                return false;
            }
        }
        
        return true;
    }
};