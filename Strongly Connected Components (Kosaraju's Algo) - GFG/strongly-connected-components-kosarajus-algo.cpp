// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	vector<bool> visited;
	vector<bool> rev_visited;
	
	// dfs function on original graph
	void dfs1(vector<int> adj[], stack<int> &st, int curr){
	    visited[curr] = true;
	    for(auto child:adj[curr]){
	        if(visited[child]==false){
	            dfs1(adj, st, child);
	        }
	    }
	    st.push(curr);
	}
	
	// dfs function on reverse graph (transpose)
	void dfs2(vector<int> adj[], int curr){
	    rev_visited[curr] = true;
	    for(auto child:adj[curr]){
	        if(rev_visited[child]==false){
	            dfs2(adj, child);
	        }
	    }
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        visited.resize(V,false);
        rev_visited.resize(V,false);
        int count = 0;
        
        stack<int> st;
        
        // do dfs on original graph and push the visited nodes to stack in reverse order
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                dfs1(adj,st,i);
            }
        }
        
        // reverse the graph (transpose graph)
        vector<int> rev[V];
        
        for(int i=0;i<V;i++){
            for(auto j:adj[i]){
                rev[j].push_back(i);
            }
        }
        
        // do dfs on the nodes present in stack. 
        // every dfs will complete a strongly connected component. so increment count
        while(!st.empty()){
            int curr = st.top();
            if(rev_visited[curr]==false){
                dfs2(rev,curr);
                count++;
            }
            st.pop();
        }
        
        return count;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends