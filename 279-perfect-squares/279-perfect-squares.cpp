class Solution {
public:
    int dp[10001];
    
    int solve(int n){
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int minVal = INT_MAX;
        // subtract square numbers in range 1 to n and find no of squares for n-i*i
        for(int i=1;i*i<=n;i++){
            minVal = min(minVal, 1 + solve(n-i*i));
        }
        return dp[n] = minVal;
    }
    
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};