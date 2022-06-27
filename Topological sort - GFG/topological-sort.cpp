// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	// Topological Sort using Kahn's Algorithm using BFS
	vector<int> topoSortBFS(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
        vector<int> topo;
	    // assign indegree for each node
	    for(int i=0;i<V;i++){
	        for(auto k:adj[i]){
	            indegree[k]++;
	        }
	    }
        // put all 0 indegree to queue. these are valid starting points
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            topo.push_back(curr);
            for(auto i:adj[curr]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
	    return topo;
	}
	
	// Topological Sort using DFS
	
	vector<int> visited;
	vector<int> topo;
	bool isCycle = false;
	
	void dfs(int curr, vector<int> adj[]){
	    if(visited[curr]==1){
	        isCycle=true;
	    }
	    visited[curr] = 1;
	    for(auto i:adj[curr]){
	        if(visited[i]==0){
	            dfs(i,adj);
	        }
	    }
	    visited[curr] = 2;
	    topo.push_back(curr);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    visited.resize(V,0);
	    for(int i=0;i<V;i++){
	        if(visited[i]==0){
	            dfs(i,adj);
	        }
	    }
	    reverse(topo.begin(),topo.end());
	    return topo;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends