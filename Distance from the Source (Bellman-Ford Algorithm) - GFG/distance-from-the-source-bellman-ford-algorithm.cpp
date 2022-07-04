// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   src: source vertex to start traversing graph with
    *   V: number of vertices
    */
    #define INF 1e8
    
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int src) {
        // adj = {{u1,v1,wt1}, {u2,v2,wt2}..}
        vector<int> dist(V,INF);
        dist[src] = 0;
        
        // run loop V-1 times. don't know reason for this
        for(int i=0;i<V-1;i++){
            for(auto it:adj){
                int u = it[0], v = it[1], wt = it[2];
                if(dist[u]!=INF && dist[v] > dist[u] + wt){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        return dist;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj;
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1;
            t1.push_back(u);
            t1.push_back(v);
            t1.push_back(w);
            adj.push_back(t1);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.bellman_ford(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends