class Solution {
public:
    int INF = INT_MAX;
    
    int dp[103][103];
    
    // solve(i,j) returns min cost to cut between index i and j not including them.
    int solve(vector<int> &cuts, int i, int j){
        // if distance of i and j cut index is 1, we cannot cut further so return 0
        if(j-i<=1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // consider cuts in range start+1 to end-1 and find which gives min cost
        // assume i to k-1 and k to j has been cut before and we got min cost in both sections
        int minVal = INF;
        int currLen = cuts[j] - cuts[i]; // current length of stick
        for(int k=i+1;k<=j-1;k++){
            minVal = min(minVal, currLen + solve(cuts,i,k) + solve(cuts,k,j));
        }
        return dp[i][j] = minVal;
    }
    
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        // insert 0 and length of stick to the cuts array
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        return solve(cuts, 0, cuts.size()-1);
    }
};