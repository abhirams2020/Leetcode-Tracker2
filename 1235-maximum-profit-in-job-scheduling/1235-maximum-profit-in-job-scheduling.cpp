/*
// USING 2D DP WITH INDEX AND PREV INDEX AS PARAMETERS
class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(vector<vector<int>>& jobs, int i, int n, int prevIdx){
        if(i==n){
            return 0;
        }
        if(dp[i][prevIdx+1]!=-1){
            return dp[i][prevIdx+1];
        }
        int include = 0, notInclude = 0;
        // start of current job should be more than or equal to end of previous one
        if(prevIdx==-1 || jobs[i][0] >= jobs[prevIdx][1]){
            include = jobs[i][2] + solve(jobs,i+1,n,i);
        }
        notInclude = solve(jobs,i+1,n,prevIdx);
        return dp[i][prevIdx+1] = max(include, notInclude);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        dp.resize(n+1, vector<int> (n+2,-1));
        vector<vector<int>> jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        int maxProfit = solve(jobs,0,n,-1);
        // by printing dp matrix, we find dp[i][j] only depends on i
        for(auto v:dp){
            for(auto i:v){
                cout<<i<<"\t";
            }
            cout<<"\n";
        }
        return maxProfit;
    }
};
*/

// USING 1D DP WITH INDEX AS PARAMETER
class Solution {
public:
    vector<int> dp;
    
    int solve(vector<vector<int>>& jobs, int i, int n, int prevEnd){
        if(i==n){
            return 0;
        }
        if(jobs[i][0]<prevEnd){
            return solve(jobs,i+1,n,prevEnd);
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i] = max(jobs[i][2] + solve(jobs,i+1,n,jobs[i][1]), solve(jobs,i+1,n,prevEnd));
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        dp.resize(n+1,-1);
        vector<vector<int>> jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        int maxProfit = solve(jobs,0,n,0);
        return maxProfit;
    }
};