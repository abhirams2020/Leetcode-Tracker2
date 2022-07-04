// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    #define INF 1e8
    
	int isNegativeWeightCycle(int V, vector<vector<int>>edges){
	    vector<int> dist(V,INF);
	    // let source be 0
	    dist[0] = 0;
	    // run loop n-1 times to get min distance from source to all nodes
	    for(int i=0;i<V-1;i++){
	        for(auto edge:edges){
	            int u=edge[0], v=edge[1], wt=edge[2];
	            if(dist[u]!=INF && dist[v]>dist[u]+wt){
	                dist[v] = dist[u] + wt;
	            }
	        }
	    }
	    
	    // check negative weight cycle
	    // if negative weight cycle exist, for an edge {u,v,wt} in edges, dist[v]>dist[u]+wt
	    for(auto edge:edges){
	        int u=edge[0], v=edge[1], wt=edge[2];
            if(dist[u]!=INF && dist[v]>dist[u]+wt){
                return true;
            }
	    }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends