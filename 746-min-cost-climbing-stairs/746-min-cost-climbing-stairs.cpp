/*
// RECURSION WITH MEMOIZATION O(N) SPACE
class Solution {
public:
    
    // dp[i] shows least cost to reach next stair from ith stair
    // mincost(i) = cost[i] + min(mincost(i-1), mincost(i-2))
    vector<int> dp;
    
    int minCost(vector<int> &cost, int index){
        // we can start from either 0 or 1
        if(index==0 || index==1){
            return cost[index];
        }
        if(index<0){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        return dp[index] = cost[index] + min(minCost(cost,index-1), minCost(cost,index-2));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n,-1);
        // we can reach top from last or second last. so choose min out of both
        return min(minCost(cost,n-1), minCost(cost,n-2));
    }
};
*/

// ITERATIVE METHOD CONSTANT SPACE USING 2 VARIABLE DP
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int first = cost[0], second = cost[1];
        for(int i=2;i<n;i++){
            int curr = cost[i] + min(first,second);
            first = second;
            second = curr;
        }
        return min(first,second);
    }
};