class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(vector<int>& nums, int& n, int index, int prevIndex){
        if(index==n){
            return 0;
        }
        if(dp[index][prevIndex+1]!=-1){
            return dp[index][prevIndex+1];
        }
        int include=0, notInclude=0;
        notInclude = solve(nums,n,index+1,prevIndex);
        if(prevIndex==-1 || nums[index]>nums[prevIndex]){
            include = 1 + solve(nums,n,index+1,index);
        }
        return dp[index][prevIndex+1] = max(include, notInclude);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1, vector<int>(n+2,-1));
        return solve(nums,n,0,-1);
    }
};