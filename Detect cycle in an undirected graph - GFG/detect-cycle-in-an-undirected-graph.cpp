// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<bool> visited;
    
    bool dfs(int curr, vector<int> adj[], int parent){
        visited[curr] = true;
        for(auto node:adj[curr]){
            if(node!=parent){
                if(visited[node]){
                    return true;
                }
                else if(dfs(node,adj,curr)){
                    return true;
                }
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