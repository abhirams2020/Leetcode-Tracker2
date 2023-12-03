//{ Driver Code Starts
#include <bits/stdc++.h>
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
        
        // run loop V-1 times
        for(int i=0;i<V-1;i++){
            for(auto it:adj){
                int u = it[0], v = it[1], wt = it[2];
                // consider a start node only if its reachable by src, ie dist[u]!=INF
                if(dist[u]!=INF && dist[v] > dist[u] + wt){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // check for negative cycle by running the loop 1 more time
        // if dist is updated again, it means negative cycle exists
        for(auto it:adj){
            int u = it[0], v = it[1], wt = it[2];
            if(dist[u]!=INF && dist[v] > dist[u] + wt){
                return {-1};
            }
        }
        return dist;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends