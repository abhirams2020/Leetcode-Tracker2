// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int dp[1001][1002];
	int solve(int arr[], int n, int index, int prevIndex){
	    if(index==n){
	        return 0;
	    }
	    if(dp[index][1 + prevIndex]!=-1){
	        return dp[index][1 + prevIndex];
	    }
	    int include = INT_MIN, notInclude = INT_MIN;
	    int prev = INT_MIN;
        if(prevIndex!=-1) {
            prev = arr[prevIndex];
        }
        if(arr[index]>prev){
            include = max(include, arr[index] + solve(arr,n,index+1,index));	            
        }
	    notInclude = max(notInclude, solve(arr,n,index+1,prevIndex));
	    return dp[index][1 + prevIndex] = max(include, notInclude);
	}
	
	int maxSumIS(int arr[], int n)  
	{
	    memset(dp,-1,sizeof(dp));
	    return solve(arr,n,0,-1);
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends