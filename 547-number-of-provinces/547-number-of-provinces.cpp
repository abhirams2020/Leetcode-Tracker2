class Solution {
public:
    vector<bool> visited;
    
    // function to do bfs from src and mark all reachable nodes
    void bfs(vector<vector<int>> &adj, int src) {
        visited[src] = true;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int v=0;v<adj.size();v++){
                if(adj[curr][v]!=0 && visited[v] == false){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size();
        int count = 0;
        visited.resize(V,false);
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                bfs(adj,i);
                count++;
            }
        }
        return count;
    }
};