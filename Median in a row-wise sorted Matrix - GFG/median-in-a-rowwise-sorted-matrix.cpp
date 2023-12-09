//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int countGreaterArr(vector<int> &arr, int target){
        int lo=0, hi=arr.size()-1;
        int ans = arr.size();
        // find smallest index such that nums[mid] > target
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(arr[mid]>target){
                ans = mid;
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }
        return arr.size()-ans;
    }
    
    int countGreaterMatrix(vector<vector<int>> &matrix, int target){
        int total = 0;
        for(int i=0;i<matrix.size();i++){
            total += countGreaterArr(matrix[i], target);
        }
        return total;
    }
    
    int median(vector<vector<int>> &matrix, int R, int C){
        int minVal=INT_MAX, maxVal=INT_MIN;
        // find min, max val
        for(auto &v:matrix){
            minVal = min(minVal, v[0]);
            maxVal = max(maxVal, v[C-1]);
        }
        int lo=minVal, hi=maxVal;
        int ans = -1;
        // binary search get mid and check number of elements in matrix > mid
        while(lo<=hi){
            int mid = lo + (hi-lo) / 2;
            int count = countGreaterMatrix(matrix,mid);
            if(countGreaterMatrix(matrix,mid) < (R*C+1)/2) {
                ans = mid;
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends