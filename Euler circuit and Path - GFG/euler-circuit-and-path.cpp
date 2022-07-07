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
    
    bool isConnected(int V, vector<int> adj[]){
        visited.resize(V,false);
        for(int i=0;i<V;i++){
            if(adj[i].size()>0){
                visited[i] = true;
                dfs(i,adj);
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
    
    int countOdd(int V, vector<int> adj[]){
        int count = 0;
        for(int i=0;i<V;i++){
            if(adj[i].size()%2 == 1){
                count++;
            }
        }
        return count;
    }
    
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