class Solution {
public:
    // dp[i+1] gives longest increasing subsequence with prevIndex = i
    int dp[2502];
    
    int solve(vector<int>& nums, int& n, int index, int prevIndex){
        if(index==n){
            return 0;
        }
        if(dp[prevIndex+1]!=-1){
            return dp[prevIndex+1];
        }
        int include=0, notInclude=0;
        notInclude = solve(nums,n,index+1,prevIndex);
        if(prevIndex==-1 || nums[index]>nums[prevIndex]){
            include = 1 + solve(nums,n,index+1,index);
        }
        return dp[prevIndex+1] = max(include, notInclude);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        int ans = solve(nums,n,0,-1);
        return ans;
    }
};