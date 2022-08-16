class Solution {
public:
    unordered_set<string> wordSet;
    
    
    bool solve(string &s, int start, int end, int dp[]){
        if(start>end){
            return true;
        }
        if(dp[start]!=-1){
            return dp[start];
        }
        for(int i=start;i<=end;i++){
            if(wordSet.count(s.substr(start,i-start+1)) && solve(s,i+1,end,dp)){
                return dp[start] = true;
            }
        }
        return dp[start] = false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto &word:words){
            wordSet.insert(word);
        }
        
        vector<string> ans;
        
        for(auto &word:words){
            int dp[301];
            memset(dp,-1,sizeof(dp));
            
            wordSet.erase(word);
            if(solve(word, 0, word.length()-1 ,dp)){
                ans.push_back(word);
            }
            wordSet.insert(word);
        }
        
        return ans;
    }
};