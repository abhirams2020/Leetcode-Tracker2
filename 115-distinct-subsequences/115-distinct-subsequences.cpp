// //  METHOD 1 : MEMOIZATION DP WITH INDEX OF S AND T AS PARAMETERS
// class Solution {
// public:
//     // dp[i][j] gives total number of possible t possible when s at index=i and t at index=j
//     int dp[1001][1001];
    
//     int solve(string &s, string &t, int i, int j){
//         if(j==t.length()){
//             return 1;
//         }
//         if(i==s.length()){
//             return 0;
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         int include=0, notInclude=0;
//         if(s[i]==t[j]){
//             include = solve(s,t,i+1,j+1);
//         }
//         notInclude = solve(s,t,i+1,j);
//         return dp[i][j] = include + notInclude;
//     }
    
//     int numDistinct(string s, string t) {
//         memset(dp,-1,sizeof(dp));
//         int ans = solve(s,t,0,0);
//         return ans;
//     }
// };

// METHOD 2 : TABULATION DP WITH INDEX OF S AND T AS PARAMETERS
class Solution {
public:
    int numDistinct(string s, string t) {
        unsigned int dp[1001][1001];
        memset(dp,-1,sizeof(dp));
        // when s index=s.length(), ans should be 0
        for(int j=0;j<=t.length();j++){
            dp[s.length()][j] = 0;
        }
        // when t index=t.length(), ans should be 1
        // assign 1 to t.length() index after assigingn 0 to s.length() index since dp[s.length()][t.length()] = 1
        for(int i=0;i<=s.length();i++){
            dp[i][t.length()] = 1;
        }
        for(int i=s.length()-1;i>=0;i--){
            for(int j=t.length()-1;j>=0;j--){
                if(s[i]==t[j]){
                    dp[i][j] = dp[i+1][j] + dp[i+1][j+1];
                }
                else {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    }
};