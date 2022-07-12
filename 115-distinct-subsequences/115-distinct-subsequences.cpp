class Solution {
public:
    int dp[1001][1001];
    
    int solve(string &s, string &t, int i, int j){
        if(j==t.length()){
            return 1;
        }
        if(i==s.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int include=0, notInclude=0;
        if(s[i]==t[j]){
            include = solve(s,t,i+1,j+1);
        }
        notInclude = solve(s,t,i+1,j);
        return dp[i][j] = include + notInclude;
    }
    
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(s,t,0,0);
    }
};