// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // // CYCLE DETECTION USING DFS ON GRAPH
    // vector<int> visited;
    
    // bool dfs(vector<int> adj[], int node){
    //     visited[node] = 1;
    //     for(auto i:adj[node]){
    //         if(visited[i] == 0){
    //             if(dfs(adj,i)){
    //                 return true;
    //             }
    //         }
    //         else if(visited[i]==1){
    //             return true;
    //         }
    //     }
    //     visited[node] = 2;
    //     return false;
    // }
    
    // bool isCyclicDFS(int V, vector<int> adj[]) {
    //     visited.resize(V,0);
    //     for(int i=0;i<V;i++){
    //         if(visited[i]==0){
    //             if(dfs(adj,i)){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }
    
    // CYCLE DETECTION USING BFS ON GRAPH
    
    bool isCyclic(int V, vector<int> adj[]) {
        int count = 0;
        vector<int> indegree(V,0);
        vector<int> topo;
        
        for(int i=0;i<V;i++){
            for(auto node:adj[i]){
                indegree[node]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            count++;
            for(auto node:adj[curr]){
                indegree[node]--;
                if(indegree[node]==0){
                    q.push(node);
                }
            }
        }
        // topological sort is applicable only for directed acyclic graph
        // if topological sort is possible for all elements, cycle will not be there
        if(count==V){
            return false;
        }
        return true;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends