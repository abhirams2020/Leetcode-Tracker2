// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	using pii = pair<int,int>;
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> parent(V), key(V,INT_MAX);
        vector<bool> MST(V,false);
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        // start from node 0
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