// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<bool> visited;
    
    void bfs(vector<vector<int>> &adj, int src) {
        visited[src] = true;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int v=0;v<adj.size();v++){
                if(adj[curr][v]!=0 && visited[v] == false){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        int count = 0;
        visited.resize(V,false);
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                bfs(adj,i);
                count++;
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends