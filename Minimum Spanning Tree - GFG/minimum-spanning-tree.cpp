// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	using pii = pair<int,int>;
	// Prim's algorithm
	// Function to find sum of weights of edges of the Minimum Spanning Tree.
    int primSpanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> parent(V), key(V,INT_MAX);
        vector<bool> MST(V,false);
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        // start from node 0
        // dist bw i and parent[i] = key[i]
        key[0] = 0;
        parent[0] = -1;
        pq.push({key[0],0});
        while(!pq.empty()){
            int minV = pq.top().second;
            pq.pop();
            MST[minV] = true;
            for(auto it:adj[minV]){
                int v = it[0];
                int wt = it[1];
                if(MST[v]==false && wt<key[v]){
                    key[v] = wt;
                    parent[v] = minV;
                    pq.push({key[v],v});
                }
            }
        }
        
        int sum = 0;
        for(auto i:key){
            sum += i;
        }
        
        return sum;
    }
    
    
	// Kruskal's algorithm

	struct node {
	    int u,v,wt;
	    node(int u, int v, int wt){
	        this->u = u;
	        this->v = v;
	        this->wt = wt;
	    }
	};
	
	static bool comp(node a, node b){
	    return a.wt < b.wt;
	}

    // Find parent of node and store it in parent[]
    int findParent(int node, vector<int> &parent) {
        if(node==parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node],parent);
    }
    
    //Function to merge two nodes a and b.
    void union_( int a, int b, vector<int> &parent, vector<int> &rank) 
    {
        if(parent[a]==parent[b]){
            return;
        }
        
        int u = findParent(a, parent);
        int v = findParent(b, parent);
        
        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else if(rank[v] < rank[u]){
            parent[v] = u;
        }
        else {
            rank[u]++;
            parent[v] = u;
        }
    }
    
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> parent(V), rank(V,0);
        for(int i=0;i<V;i++){
            parent[i] = i;
        }
        
        vector<node> edges;
        // add edges to edges array
        for(int u=0;u<V;u++){
            for(auto it:adj[u]){
                int v = it[0];
                int wt = it[1];
                edges.push_back(node(u,v,wt));
            }
        }
        int n = edges.size();
        // sort the edges in increasing order
        sort(edges.begin(), edges.end(), comp);
        
        vector<pair<int,int>> MST; // to store edges present in mst
        int sum = 0;
        // in kruskal, select smallest edges till we dont create a cycle
        for(auto it:edges){
            if(findParent(it.u,parent) != findParent(it.v,parent)){
                sum += it.wt;
                union_(it.u, it.v, parent, rank);
                MST.push_back({it.u,it.v});
            }
        }
        
        return sum;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends