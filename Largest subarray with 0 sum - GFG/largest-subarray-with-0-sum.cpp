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
        mp[0] = -1;
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