class Solution {
public:
    vector<int> topo;
    int visited[2001];
    // visited set for checking if node visited again during dfs
    // 0 -> node not visited
    // 1 -> node visited
    // 2 -> node visited and the course can be taken
    
    bool isCycle(vector<vector<int>> &graph, int curr){
        visited[curr] = 1;
        for(auto child:graph[curr]){
            if(visited[child] == 0){
                visited[child] = 1;
                if(isCycle(graph,child) == true){
                    return true;
                }
            }
            else if(visited[child] == 1){
                return true;
            }
        }
        visited[curr] = 2;
        topo.push_back(curr);
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        memset(visited,0,sizeof(visited));
        // graph[curr] gives list of prerequisites
        vector<vector<int>> graph(numCourses+1);
        for(auto it:prerequisites){
            graph[it[0]].push_back(it[1]);
        }
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                if(isCycle(graph,i)==true){
                    return {};
                }
            }
        }
        
        return topo;
    }
};