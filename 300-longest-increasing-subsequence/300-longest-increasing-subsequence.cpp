// // METHOD 1 : Memoization DP by taking curr index and prev index as parameters.
// class Solution {
// public:
//     vector<vector<int>> dp;

//     int solve(vector<int>& nums, int& n, int index, int prevIndex){
//         if(index==n){
//             return 0;
//         }
//         if(dp[index][prevIndex+1]!=-1){
//             return dp[index][prevIndex+1];
//         }
//         int include=0, notInclude=0;
//         notInclude = solve(nums,n,index+1,prevIndex);
//         if(prevIndex==-1 || nums[index]>nums[prevIndex]){
//             include = 1 + solve(nums,n,index+1,index);
//         }
//         return dp[index][prevIndex+1] = max(include, notInclude);
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         dp.resize(n+1, vector<int>(n+2,-1));
//         return solve(nums,n,0,-1);
//     }
// };

// // METHOD 2 : Memoization DP by taking only prev index as parameter
// class Solution {
// public:
//     // dp[i+1] gives longest increasing subsequence with prevIndex = i
//     // prevIndex range = -1 to 2500. Since -1 index not possible, take prevIndex+1
//     int dp[2501];
//     int solve(vector<int>& nums, int& n, int index, int prevIndex){
//         if(index==n){
//             return 0;
//         }
//         if(dp[prevIndex+1]!=-1){
//             return dp[prevIndex+1];
//         }
//         int include=0, notInclude=0;
//         notInclude = solve(nums,n,index+1,prevIndex);
//         if(prevIndex==-1 || nums[index]>nums[prevIndex]){
//             include = 1 + solve(nums,n,index+1,index);
//         }
//         return dp[prevIndex+1] = max(include, notInclude);
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         memset(dp,-1,sizeof(dp));
//         int ans = solve(nums,n,0,-1);
//         return ans;
//     }
// };

// // METHOD 3 : Tabulation DP by taking curr index and prev index as parameters.
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         int dp[n+1][n+1];
//         memset(dp,-1,sizeof(dp));
//         // when index==n, result is 0.
//         for(int prevIndex=-1;prevIndex<=n-1;prevIndex++){
//             dp[n][prevIndex+1] = 0;
//         }
//         for(int index=n-1;index>=0;index--){
//             for(int prevIndex=index-1;prevIndex>=-1;prevIndex--){
//                 if(prevIndex==-1 || nums[index]>nums[prevIndex]){
//                     dp[index][prevIndex+1] = max(1+dp[index+1][index+1], dp[index+1][prevIndex+1]);
//                 }
//                 else {
//                     dp[index][prevIndex+1] = dp[index+1][prevIndex+1];
//                 }
//             }
//         }
//         // int ans = solve(nums,n,0,-1) = dp[0][-1+1] = dp[0][0]
//         return dp[0][0];
//     }
// };

// METHOD 4 : Tabulation DP by taking only prev index as parameter
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        // when index==n, result is 0.
        for(int prevIndex=-1;prevIndex+1<n+1;prevIndex++){
            dp[prevIndex+1] = 0;
        }
        for(int index=n-1;index>=0;index--){
            for(int prevIndex=index-1;prevIndex>=-1;prevIndex--){
                if(prevIndex==-1 || nums[index]>nums[prevIndex]){
                    dp[prevIndex+1] = max(1+dp[index+1], dp[prevIndex+1]);
                }
                else {
                    dp[prevIndex+1] = dp[prevIndex+1];
                }
            }
        }
        // int ans = solve(nums,n,0,-1) = dp[-1+1] = dp[0]
        return dp[0];
    }
};