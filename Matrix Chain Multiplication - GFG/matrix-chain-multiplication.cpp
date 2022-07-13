// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

// class Solution{
// public:
//     int dp[101][101];
    
//     int solve(int arr[], int i, int j){
//         // if size of i to j less than 3, MCM not possible
//         if(j-i+1 < 3){
//             return 0;
//         }
//         // if(dp[i][j]!=-1){
//         //     return dp[i][j];
//         // }
//         int ans = INT_MAX;
//         for(int k=i+1; k<=j-1; k++){
//             ans = min(ans, arr[i]*arr[k]*arr[j] + solve(arr,i,k-1) + solve(arr,k+1,j));
//         }
//         return dp[i][j] = ans;
//     }
    
//     int matrixMultiplication(int N, int arr[])
//     {
//         memset(dp,-1,sizeof(dp));
//         return solve(arr,0,N-1);
//     }
// };

class Solution{
public:
    int dp[101][101];
    
    // IMP : MCM(i,j) gives min no of multiplications reqd between i and j not including it.
    int MCM(int arr[], int i, int j) {
        if(j-i+1 < 3) {
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int minVal = INT_MAX;
        // k paritions the array to 2 parts, i to k and k to j.
        // fn[i,j] = min no of operations possible by multiplying in range [i+1, j-1].
        // fn[i,j] = min {nums[i]*nums[k]*nums[j] + fn[i,k] + fn[k,j]}
        for(int k=i+1;k<=j-1;k++) {
            minVal = min(minVal, arr[i]*arr[k]*arr[j] + MCM(arr,i,k) + MCM(arr,k,j));
        }
        return dp[i][j] = minVal;
    }

    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        return MCM(arr,0,N-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends