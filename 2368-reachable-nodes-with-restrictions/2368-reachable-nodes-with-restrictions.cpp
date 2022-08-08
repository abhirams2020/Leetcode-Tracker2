class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;
    
    void dfs(int src, unordered_set<int> &restrictedSet){
        for(auto child:adj[src]){
            if(visited[child]==false && restrictedSet.count(child)==0){
                visited[child] = true;
                dfs(child, restrictedSet);
            }
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        adj.resize(n);
        visited.resize(n,false);
        unordered_set<int> restrictedSet;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(auto i:restricted){
            restrictedSet.insert(i);
        }
        visited[0] = true;
        dfs(0,restrictedSet);
        int count = 0;
        for(int i=0;i<visited.size();i++){
            if(visited[i] == true){
                count++;
            }
        }
        return count;
    }
};