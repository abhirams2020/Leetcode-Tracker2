// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> mp;
        int maxLen = 0;
        int pre = 0;
        // mp[0] = -1 cz if sum from 0 to i is 0, then len = i-(-1) = i+1
        mp[0] = -1;
        // for every i, check if prefix sum already found before
        // if prefix sum was found, then prev_index+1 to curr_index has 0 sum
        // if prefix sum not found, this is first occurrence.store index of prefix sum
        for(int i=0;i<A.size();i++){
            pre += A[i];
            if(mp.count(pre)){
                int r = i;
                int l = mp[pre];
                maxLen = max(maxLen, r-l);
            }
            else {
                mp[pre] = i;
            }
        }
        return maxLen;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends