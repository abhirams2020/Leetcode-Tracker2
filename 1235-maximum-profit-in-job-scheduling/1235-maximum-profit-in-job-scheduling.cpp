class Solution {
public:
    vector<int>dp;
    int find(vector<vector<int>>& events,int idx,int end){
        // We reach final index, return 0
        if(idx==events.size())
            return 0;
        // If the current start time is less than previous end time then we can't attend this event, we move forward.
        if( events[idx][0] < end )
            return find( events, idx + 1 , end );
        if( dp[idx] != -1)
            return dp[idx];
        // Return pre stored value if we have 
        int res= max ( events[idx][2] + find(events, idx + 1 , events[idx][1] ),  find(events , idx + 1 , end ) );
        return dp[idx] = res;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
    {
        //putting startTime,endTimeand profit in an array so that we can sort it
        vector<vector<int>>events(startTime.size(),vector<int>(3,0));
        for(int i=0;i<startTime.size();i++)
        {
            events[i][0]=startTime[i];
            events[i][1]=endTime[i];
            events[i][2]=profit[i];
        }
        sort(events.begin() , events.end());
        int n = events.size();
        //Intialising DP and assigning value -1
        dp.resize( n,-1);
        int res = find(events , 0 , 0);
        // for(auto i:dp){
        //     cout<<i<<" ";
        // }
        // cout<<"\n";
        return res;
    }
};