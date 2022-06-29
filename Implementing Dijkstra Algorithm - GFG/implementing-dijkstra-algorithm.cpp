// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	using pii = pair<int,int>;
	
	vector<int> dist;
	
	// dijkstra is like bfs with priority queue with {dist,node} values
	void dijkstra(vector<vector<int>> adj[], int node){
	    priority_queue<pii, vector<pii>, greater<pii>> pq;
	    pq.push({0,node});
	    dist[node] = 0;
	    while(!pq.empty()){
            int curr = pq.top().second;
            pq.pop();
            for(auto child:adj[curr]){
                int child_node = child[0];
                int child_dist = child[1];
                if(dist[curr] + child_dist < dist[child_node]){
                    dist[child_node] = dist[curr] + child_dist;
                    pq.push({dist[child_node], child_node});
                }
            }
	    }
	}
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // adj[node] = {{neighbour,distance}, {neighbour,distance}}
        dist.resize(V,INT_MAX);
        dijkstra(adj,S);
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends