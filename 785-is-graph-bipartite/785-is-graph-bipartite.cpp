class Solution {
public:
    vector<int> colors;
    
    // DFS traversal
    bool checkDFS(vector<vector<int>>& graph, int parent){
        // check the child nodes. if not colored before, color it and do dfs
        // if colored before, check if parent and child have different color
        for(auto j:graph[parent]){
            if(colors[j]==0){
                colors[j] = -colors[parent];
                if(checkDFS(graph,j)==false){
                    return false;
                }               
            }
            else {
                if(colors[j] != -colors[parent]){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        colors.resize(n,0);
        for(int i=0;i<n;i++){
            if(colors[i]==0){
                colors[i] = 1;
                if(checkDFS(graph,i)==false){
                    return false;
                }
            }
        }
        return true;
    }
};