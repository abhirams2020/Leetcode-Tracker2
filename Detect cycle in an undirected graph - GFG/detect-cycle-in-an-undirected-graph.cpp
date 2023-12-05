//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> visited;
    // Function to detect cycle in an undirected graph.
    bool dfs(int curr, int prev, vector<int> adj[]){
        visited[curr] = 1;
        for(auto &nbr:adj[curr]){
            if(nbr==prev){
                continue;
            }
            if(visited[nbr]==0 && dfs(nbr,curr,adj)==true){
                return true;
            }
            if(visited[nbr]==1){
                return true;
            }
        }
        visited[curr] = 2; // curr visited and no cycle found in dfs
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        visited.resize(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]==0 && dfs(i,-1,adj)==true){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
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
}
// } Driver Code Ends