class Solution {
public:
    int dp[501][501];
    
    int solve(string& word1, string& word2, int i, int j){
        // if we reached end of both, it means word1==word2
        if(i==0 && j==0){
            return 0;
        }
        // if we reached end of word1, insert remaining characters of word2 to word1.
        if(i==0){
            return dp[i][j] = j;
        }
        // if we reached end of word2, remove extra characters from word1.
        if(j==0){
            return dp[i][j] = i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i-1]==word2[j-1]){
            return dp[i][j] = solve(word1,word2,i-1,j-1);
        }
        
        int ins = solve(word1,word2,i,j-1);
        int del = solve(word1,word2,i-1,j);
        int rep = solve(word1,word2,i-1,j-1);
        
        return dp[i][j] = 1 + min({ins,del,rep});
    }
    
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,word1.length(),word2.length());
    }
};