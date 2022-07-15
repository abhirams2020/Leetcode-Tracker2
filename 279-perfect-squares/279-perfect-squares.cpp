class Solution {
public:
    int dp[10001];
        
    int solve(int sum){
        if(sum==0){
            return 0;
        }
        if(dp[sum]!=-1){
            return dp[sum];
        }
        int count = INT_MAX;
        for(int i=1;i*i<=sum;i++){
            count = min(count, 1 + solve(sum-i*i));
        }
        return dp[sum] = count;
    }
    
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};