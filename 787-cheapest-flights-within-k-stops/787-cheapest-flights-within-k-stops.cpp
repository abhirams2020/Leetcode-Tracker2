class Solution {
public:
    void copyVec(int n, vector<int> &arr1, vector<int> &arr2){
        for(int i=0;i<n;i++){
            arr2[i] = arr1[i];
        }    
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // flights = {{u1,v1,wt1}, {u2,v2,wt2}..}
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        
        // since max no of stops = k, it means we can do bellman ford for k nodes from source = k+1 edges
        for(int i=0;i<k+1;i++){
            vector<int> temp(n);
            // copy dist to temp
            copyVec(n,dist,temp);
            for(auto it:flights){
                int u = it[0], v = it[1], wt = it[2];
                // consider a start node only if its reachable by src, ie dist[u]!=INT_MAX
                if(dist[u]!=INT_MAX && temp[v] > dist[u] + wt){
                    temp[v] = dist[u] + wt;
                }
            }
            // copy temp to dist
            copyVec(n,temp,dist);
        }
        
        if(dist[dst]!=INT_MAX){
            return dist[dst];
        }
        return -1;
    }
};