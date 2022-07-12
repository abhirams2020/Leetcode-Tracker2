// // METHOD 1 : MEMOIZATION DP WITH NO OF REMAINING ELEMENTS i AND j AS PARAMETERS
// class Solution {
// public:
//     int dp[501][501];
    
//     // solve(s1,s2,i,j) -> min no of operations to make s1 to s2 when s1 has i characters left and s2 has j characters left
//     // each time, we make word1[i-1]==word2[j-1] or remove a character and proceed to next step.
//     int solve(string& word1, string& word2, int i, int j){
//         // if we reached end of both, it means word1==word2
//         if(i==0 && j==0){
//             return 0;
//         }
//         // if we reached end of word1, insert remaining characters of word2 to word1.
//         if(i==0){
//             return dp[i][j] = j;
//         }
//         // if we reached end of word2, remove extra characters from word1.
//         if(j==0){
//             return dp[i][j] = i;
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         // if both index characters are equal no operation is done. move both index by 1.
//         if(word1[i-1]==word2[j-1]){
//             return dp[i][j] = solve(word1,word2,i-1,j-1);
//         }
//         // everytime, we find result when the current word1[i] is deleted, replaced or other character is inserted
        
//         // insert -> word2[j] is inserted to word1. move j but i remains at same character.
//         int ins = solve(word1,word2,i,j-1);
//         // delete -> word1[i] is deleted. So move i to next index but j remains at same place.
//         int del = solve(word1,word2,i-1,j);
//         // replace -> word1[i] is replaced with word2[j]. move both i and j to next index.
//         int rep = solve(word1,word2,i-1,j-1);
        
//         // find min of result after all 3 operations and assign to dp[i][j]
//         // since we are doing an operation, add 1 to the result.
//         return dp[i][j] = 1 + min({ins,del,rep});
//     }
    
//     int minDistance(string word1, string word2) {
//         memset(dp,-1,sizeof(dp));
//         return solve(word1,word2,word1.length(),word2.length());
//     }
// };

// METHOD 1 : TABULATION DP WITH NO OF REMAINING ELEMENTS i AND j AS PARAMETERS
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(), n=word2.length();
        int dp[m+1][n+1];
        memset(dp,-1,sizeof(dp));
        // BASE CONDITION. If i==0, return j. If j==0, return i.
        for(int i=0;i<m+1;i++){
            dp[i][0] = i;
        }
        for(int j=0;j<n+1;j++){
            dp[0][j] = j;
        }
        // i and j are no of words remaining from word1 and word2
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    // do 1 operation and take min after doing those operations
                    int ins = dp[i][j-1];
                    int del = dp[i-1][j];
                    int rep = dp[i-1][j-1];
                    dp[i][j] = 1 + min({ins,del,rep});
                }
            }
        }
        // final answer = solve(word1,word2,m,n) = dp[m][n]
        return dp[m][n];
    }
};