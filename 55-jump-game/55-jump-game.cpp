// USING DYNAMIC PROGRAMMING
class Solution {
public:
    // dp[idx] tells if it is possible to reach end index from idx
    int dp[10001];
    
    bool solve(vector<int> &nums, int index){
        if(index>=nums.size()-1){
            return true;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        for(int i=nums[index];i>=1;i--){
            int new_index = index + i;
            if(solve(nums, new_index)==true){
                return dp[index] = true;
            }
        }
        return dp[index] = false;
    }
    
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0);
    }
};