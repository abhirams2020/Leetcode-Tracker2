class Solution {
public:
//     unordered_map<int,vector<int>> adj;
//     vector<bool> visited;
    
//     void dfs(int src, unordered_set<int> &restrictedSet){
//         for(auto child:adj[src]){
//             if(visited[child]==false && restrictedSet.count(child)==0){
//                 visited[child] = true;
//                 dfs(child, restrictedSet);
//             }
//         }
//     }
    
//     int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
//         visited.resize(n,false);
//         unordered_set<int> restrictedSet;
//         for(auto it:edges){
//             adj[it[0]].push_back(it[1]);
//             adj[it[1]].push_back(it[0]);
//         }
//         for(auto i:restricted){
//             restrictedSet.insert(i);
//         }
//         visited[0] = true;
//         dfs(0,restrictedSet);
//         int count = 0;
//         for(int i=0;i<visited.size();i++){
//             if(visited[i] == true){
//                 count++;
//             }
//         }
//         return count;
//     }
    void DFS(int &n, unordered_map<int,vector<int>> &graph, vector<int> &visited, int sv, int &ans)
    {
        visited[sv] = 1;
        ans++;

        for (int i = 0; i < graph[sv].size(); i++)
        {
            int nv = graph[sv][i];
            if ( visited[nv] == 0 )
            {
                DFS(n, graph, visited, nv, ans);
            }
        }
    }

    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted)
    {
        unordered_map<int,vector<int>> graph;
        vector<int> visited(n, 0);

        for (auto &it : restricted)
        {
            visited[it] = 1;
        }

        for (int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // set<int>s(restricted.begin(), restricted.end());

        int ans = 0;
        DFS(n, graph, visited, 0, ans);

        return ans;
    }
};