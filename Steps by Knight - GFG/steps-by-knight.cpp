// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    vector<pair<int,int>> moves = {
        {2,1}, {2,-1},
        {-2,1}, {-2,-1},
        {1,2}, {1,-2},
        {-1,2}, {-1,-2}
    };
    
    // index is starting from 1 to N
    bool isValid(int x, int y, int N){
        if(x<1 || y<1 || x>=N+1 || y>=N+1){
            return false;
        }
        return true;
    }
    
    // Function to find out minimum steps Knight needs to reach target position.
    // Just perform BFS on the matrix. When knight reaches x,y that means
    // it is shortest distance possible from start. So update dist[x][y] and mark visited
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int sourceX = KnightPos[0];
	    int sourceY = KnightPos[1];
	    int destX = TargetPos[0];
	    int destY = TargetPos[1];
	    
	    // steps[x][y] gives no of steps to reach [x][y] from source
	    vector<vector<int>> steps(N+1, vector<int> (N+1,INT_MAX));
	    vector<vector<bool>> visited(N+1,vector<bool> (N+1,false));
	    
	    queue<pair<int,int>> q;
	    q.push({sourceX,sourceY});
	    visited[sourceX][sourceY] = true;
	    steps[sourceX][sourceY] = 0;
	    
	    while(!q.empty()){
	        int x = q.front().first;
	        int y = q.front().second;
	        q.pop();
	        for(auto move:moves){
	            int childX = x + move.first;
	            int childY = y + move.second;
	            if(isValid(childX,childY,N) && !visited[childX][childY]){
	                steps[childX][childY] = 1 + steps[x][y];
	                visited[childX][childY] = true;
	                q.push({childX,childY});
	            }
	        }
	        if(steps[destX][destY]!=INT_MAX){
	            break;
	        }
	    }
	    if(steps[destX][destY]==INT_MAX){
	        return -1;
	    }
	    return steps[destX][destY];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends