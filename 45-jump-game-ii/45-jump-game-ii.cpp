/*
// USING MEMOIZATION DP
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
*/

// USING BFS. FROM EACH NODE, ITS NEIGHBOURS ARE CURR_INDEX + J WHERE J = [1,nums[CURR_INDEX]]
// FROM EACH POSITION WE CAN JUMP TO i+1 to i+nums[i]
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int end = nums.size()-1;
        queue<int> q; // q for storing index
        q.push(0);
        int jumps = 0;

        vector<bool> visited(nums.size(), false);
        visited[0] = true;

        while(!q.empty()){
            int n = q.size();
            // going through all jumps for each element in queue
            for(int i=0;i<n;i++){
                int curr_i = q.front();
                q.pop();
                // if current index has reached end, return no of jumps
                if(curr_i >= end){
                    return jumps;
                }
                for(int j=nums[curr_i];j>=1;j--){
                    // if we visit an index inside array, mark it as visited to avoid repetition
                    if(curr_i+j<=nums.size()-1 && visited[curr_i+j]==false){
                        visited[curr_i+j] = true;
                        q.push(curr_i+j);
                    }
                    else if(curr_i+j > nums.size()-1){
                        q.push(curr_i+j);
                    }
                }
            }
            jumps++;
        }
        return jumps;
    }
};