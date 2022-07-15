// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int dp[81];
    
    // solve(n) = solve(n-1) + solve(n-4). we can place tile horizontally or vertically
    long long int solve(int N){
        // base case. when no of rows <= 3, we cannot place tile vertically. so only 1 way.
        if(N<=3){
            return 1;
        }
        if(dp[N]!=-1){
            return dp[N];
        }
        return dp[N] = solve(N-1) + solve(N-4);
    }
    
    long long int arrangeTiles(int N){
        memset(dp,-1,sizeof(dp));
        return solve(N);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends