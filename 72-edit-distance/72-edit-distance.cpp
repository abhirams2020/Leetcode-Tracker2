class Solution {
public:
    int dp[501][501];
    
    // solve(s1,s2,i,j) -> min no of operations to make s1 to s2 when s1 has i characters left and s2 has j characters left
    // each time, we make word1[i-1]==word2[j-1] or remove a character and proceed to next step.
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
        // if both index characters are equal no operation is done. move both index by 1.
        if(word1[i-1]==word2[j-1]){
            return dp[i][j] = solve(word1,word2,i-1,j-1);
        }
        // everytime, we find result when the current word1[i] is deleted, replaced or other character is inserted
        // since we are doing an operation, add 1 to the result.
        
        // insert -> word2[j] is inserted to word1. move j but i remains at same character.
        int ins = solve(word1,word2,i,j-1);
        // delete -> word1[i] is deleted. So move i to next index but j remains at same place.
        int del = solve(word1,word2,i-1,j);
        // replace -> word1[i] is replaced with word2[j]. move both i and j to next index.
        int rep = solve(word1,word2,i-1,j-1);
        
        // find min of result after all 3 operations and assign to dp[i][j]
        return dp[i][j] = 1 + min({ins,del,rep});
    }
    
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,word1.length(),word2.length());
    }
};