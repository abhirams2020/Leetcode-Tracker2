class Solution {
public:
    int INF = 1e5;
    
    int dp[10001];
    // solve(i) gives min no of jumps from i to reach end
    int solve(vector<int>& nums, int i){
        if(i>=nums.size()-1){
            return 0;
        }
        if(nums[i]==0){
            return INF;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int minVal = INF;
        for(int j=1;j<=nums[i];j++){
            minVal = min(minVal, solve(nums,i+j));
        }
        return dp[i] = 1 + minVal;
    }
    
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0);
    }
};