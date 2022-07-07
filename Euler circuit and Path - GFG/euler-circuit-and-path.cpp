// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<bool> visited;
    
    void dfs(int curr, vector<int> adj[]){
        for(auto child:adj[curr]){
            if(visited[child]==false){
                visited[child] = true;
                dfs(child,adj);
            }
        }
    }
    
    // Check if the valid nodes ,ie degree > 0 is in same component
    // Do dfs on a valid node and after dfs check if any other valid node is unvisited
    bool isConnected(int V, vector<int> adj[]){
        visited.resize(V,false);
        for(int i=0;i<V;i++){
            if(adj[i].size()>0){
                visited[i] = true;
                dfs(i,adj);
                // since we visited all nodes in the component, exit the loop
                break;
            }
        }
        
        for(int i=0;i<V;i++){
            if(adj[i].size()>0 && visited[i]==false){
                return false;
            }
        }
        
        return true;
    }
    
    // Count no of nodes with odd degree in graph
    int countOdd(int V, vector<int> adj[]){
        int count = 0;
        for(int i=0;i<V;i++){
            if(adj[i].size()%2 == 1){
                count++;
            }
        }
        return count;
    }
    
    // The fn returns 
    // 1 if graph contains Eulerian Path, 
    // 2 if graph contains Eulerian Circuit 
    // 0 otherwise.
	int isEularCircuit(int V, vector<int> adj[]){
	    if(isConnected(V,adj)==false){
	        return 0;
	    }
	    int count = countOdd(V,adj);
	    if(count == 0){
	        return 2;
	    }
	    if(count == 2){
	        return 1;
	    }
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEularCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}  // } Driver Code Ends