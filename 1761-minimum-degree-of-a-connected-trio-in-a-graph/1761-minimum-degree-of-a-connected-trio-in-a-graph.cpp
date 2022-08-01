class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        // since undirected graph, degree of both vertex increase for an edge
        vector<int> degree(n+1,0);
        vector<vector<int>> adj (n+1, vector<int> (n+1, 0));
        
        for(auto it:edges){
            adj[it[0]][it[1]] = 1;
            adj[it[1]][it[0]] = 1;
            
            degree[it[0]]++;
            degree[it[1]]++;
        }
        
        int minDegree = INT_MAX;
        
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if(adj[i][j]==1 && adj[j][k]==1 && adj[k][i]==1){
                        // since between a trio, there is 6 degree, total degree - 6 will give reqd ans
                        int currDegree = degree[i]+degree[j]+degree[k]-6;
                        minDegree = min(minDegree, currDegree);
                    }
                }
            }
        }
        
        if(minDegree==INT_MAX){
            return -1;
        }
        return minDegree;
    }
};