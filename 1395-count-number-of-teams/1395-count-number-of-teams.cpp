class Solution {
public:
    int dp[2][4][1002];
    
    // similar to knapsack dp problems
    int countTeams(vector<int>& rating, int idx, int prevIdx, int teamSize, bool incr){
        if(teamSize==3){
            return 1;
        }
        // reached end without having 3 members
        if(idx==rating.size()){
            return 0;
        }
        if(dp[incr][teamSize][prevIdx+1]!=-1){
            return dp[incr][teamSize][prevIdx+1];
        }
        
        int incl = 0, notIncl = 0;
        // the function should return count of teams when curr is included + count when not included
        if(prevIdx==-1  || (incr==true && rating[prevIdx]<rating[idx]) 
                        || (incr==false && rating[prevIdx]>rating[idx])){
            // when curr is valid and included, prevIdx is idx and teamSize incremented by 1
            return  dp[incr][teamSize][prevIdx+1] = countTeams(rating, idx+1, idx, teamSize+1, incr) +
                                                    countTeams(rating, idx+1, prevIdx, teamSize, incr);
        }
        else {
            return dp[incr][teamSize][prevIdx+1] = countTeams(rating, idx+1, prevIdx, teamSize, incr);
        }
    }
    
    int numTeams(vector<int>& rating) {
        memset(dp,-1,sizeof(dp));
        
        int incrCount = countTeams(rating,0,-1,0,true);
        int decrCount = countTeams(rating,0,-1,0,false);
        
        return incrCount + decrCount;
    }
};