// DP with divide and conquer
// Matrix chain multiplication
class Solution {
public:
    int dp[305][305];
    
    int solve(vector<int> &nums, int i, int j, int left, int right){
        if(i>j){
            return 0;
        }
        // if only 1 element left, return left*curr*right
        if(i==j){
            return dp[i][j] = left*nums[i]*right;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // k partitions the array to 2 parts [i,k] and [k,j]
        // we consider all elements other than k in i to j range is burst
        // for most coins, if last element is nums[k], find most coins possible when i to k and k to j was burst.
        
        // fn[x,y] = max no of coins possible by bursting baloons bw and not including x and y
        // fn[l,r] = max {nums[i-1]*nums[i]*nums[i+1] + fn[l,i] + fn[i,r]}
        int maxVal = 0;
        
        for(int k=i;k<=j;k++){
            maxVal = max(maxVal,
                         left*nums[k]*right + solve(nums, i,k-1, left,nums[k]) + solve(nums, k+1,j, nums[k],right));
        }
        return dp[i][j] = maxVal;
    }
    
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,nums.size()-1,1,1);
    }
};