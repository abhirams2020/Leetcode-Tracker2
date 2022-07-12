class Solution {
public:
    int dp[501][501];
    
    int solve(string& word1, string& word2, int i, int j, int n1, int n2){
        // if we reached end of both, it means word1==word2
        if(j>=word2.length() && i>=word1.length()){
            return 0;
        }
        // if we reached end of word1,  word1[0 to n1-1] == word2[0 to n1-1]. add word2[n1 to n2-1] to word1.
        if(i>=word1.length()){
            return dp[i][j] = (n2-1)-n1+1;
        }
        if(j>=word2.length()){
            return dp[i][j] = (n1-1)-n2+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i]==word2[j]){
            return dp[i][j] = solve(word1,word2,i+1,j+1,n1,n2);
        }
        int ins=INT_MAX, del=INT_MAX, rep=INT_MAX;
        
        ins = min(ins, solve(word1,word2,i,j+1,n1+1,n2));
        del = min(del, solve(word1,word2,i+1,j,n1-1,n2));
        rep = min(rep, solve(word1,word2,i+1,j+1,n1,n2));
        
        return dp[i][j] = 1 + min(ins, min(del,rep));
    }
    
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,0,0,word1.length(),word2.length());
    }
};