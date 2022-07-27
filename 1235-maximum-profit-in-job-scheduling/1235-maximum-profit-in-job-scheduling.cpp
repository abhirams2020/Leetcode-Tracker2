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
        for(auto i:dp){
            cout<<i<<"\t";
        }
        cout<<"\n";
        return maxProfit;
    }
};