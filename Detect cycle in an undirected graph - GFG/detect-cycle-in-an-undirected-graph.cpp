// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<bool> visited;
    
    bool dfs(int curr, vector<int> adj[], int parent){
        visited[curr] = true;
        for(auto child:adj[curr]){
            // if we havent visited a child yet, do dfs on that child and check cycle
            if(visited[child]==false) {
                if(dfs(child,adj,curr))
                    return true;
            }
            // if visited the child, check if parent of curr. if its not parent, cycle exist
            else if(child!=parent) {
                return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        visited.resize(V,false);
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                if(dfs(i,adj,-1)){
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends