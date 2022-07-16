/*
// Memoization DP start and end index as parameter
// Matrix chain multiplication with divide and conquer
class Solution {
public:
    int dp[302][302];
    
    int solve(vector<int> &nums, int i, int j){
        // if size becomes 2, then we cannot burst baloon
        if(j-i+1 <= 2){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // k partitions the array to 2 parts [i,k] and [k,j]
        // we consider all elements other than k in i+1 to j-1 range is burst
        // for most coins, if last element is nums[k], find most coins possible when i+1 to k and k to j-1 was burst.
        
        // fn[i,j] = max no of coins possible by bursting baloons in range [i+1, j-1].
        // fn[i,j] = max {nums[i]*nums[k]*nums[j] + fn[i,k] + fn[k,j]}
        // NOTE : nums[k-1]*nums[k]*nums[k+1] gives wrong answer since i+1 to k-1 and k+1 to j-1 baloons have burst before
        int maxVal = 0;
        
        for(int k=i+1;k<=j-1;k++){
            maxVal = max(maxVal,  nums[i]*nums[k]*nums[j] + solve(nums, i, k) + solve(nums, k, j));
        }
        return dp[i][j] = maxVal;
    }
    
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        int ans = solve(nums,0,n-1);
        return ans;
    }
};
*/

// Tabulation DP start and end index as parameter
// Matrix chain multiplication with divide and conquer
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n = nums.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));

        // dont know why i and j taken in this order
        for(int i=n-1;i>=0;i--) {
            for(int j=0;j<=n-1;j++) {
                if(j-i+1<=2)
                    continue;
                
                int maxVal = 0;
                for(int k=i+1;k<=j-1;k++) {
                    int cost = nums[i]*nums[k]*nums[j] + dp[i][k] + dp[k][j];  
                    maxVal = max(maxVal,cost);
                }
                dp[i][j] = maxVal;
            }
        }
        // solve(0,n-1) = dp[0][n-1]
        return dp[0][n-1];
    }
};