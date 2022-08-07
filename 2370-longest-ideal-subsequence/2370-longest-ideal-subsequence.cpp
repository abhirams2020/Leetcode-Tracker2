class Solution {
public:
    int dp[100004][128];
    
    int findLongest(string &s, int k, int i, int prev){
        if(i==s.length()){
            return 0;
        }
        if(dp[i][prev+1] != -1){
            return dp[i][prev+1];
        }
        int include = 0, notInclude = 0;
        if(prev==-1 || (abs(s[i]-prev)<=k)){
            include = 1 + findLongest(s,k,i+1,s[i]);
            notInclude = findLongest(s,k,i+1,prev);
        }
        else {
            notInclude = findLongest(s,k,i+1,prev);
        }
        return dp[i][prev+1] = max(include, notInclude);
    }
    
    int longestIdealString(string &s, int k) {
        memset(dp,-1,sizeof(dp));
        return findLongest(s,k,0,-1);
    }
};