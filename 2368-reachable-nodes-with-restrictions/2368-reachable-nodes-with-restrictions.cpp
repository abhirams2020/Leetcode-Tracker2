class Solution {
public:
    unordered_map<int,vector<int>> adj;
    vector<bool> visited;
    int count = 0;
    
    void dfs(int src){
        // for every valid node that is visited, increment count
        count++;
        for(auto child:adj[src]){
            if(visited[child]==false){
                visited[child] = true;
                dfs(child);
            }
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        visited.resize(n,false);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        // mark all restricted nodes as visited to avoid visiting it again during dfs
        for(auto i:restricted){
            visited[i] = true;
        }
        visited[0] = true;
        dfs(0);
        return count;
    }
};