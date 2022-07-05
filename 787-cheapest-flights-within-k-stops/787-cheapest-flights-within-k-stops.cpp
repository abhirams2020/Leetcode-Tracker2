// // BELLMAN FORD ALGO
// class Solution2 {
// public:
//     void copyVec(int n, vector<int> &arr1, vector<int> &arr2){
//         for(int i=0;i<n;i++){
//             arr2[i] = arr1[i];
//         }    
//     }
    
//     // USING BELLMAN FORD ALGORITHM. INSTEAD OF DIRECTLY CHANGING DIST[], COPY THE NEW VALUES IN TEMP[]
//     // COPYING TO TEMP WILL ENSURE THAT WE DONT USE NEW DIST VALUE FOR CURR LOOP AND MAINTAIN K STOPPING POINTS
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         // flights = {{u1,v1,wt1}, {u2,v2,wt2}..}
//         vector<int> dist(n,INT_MAX);
//         dist[src] = 0;
        
//         // since max no of stops = k, it means we can do bellman ford for k nodes from source = k+1 edges
//         for(int i=0;i<k+1;i++){
//             vector<int> temp(n);
//             // copy dist to temp
//             copyVec(n,dist,temp);
//             for(auto it:flights){
//                 int u = it[0], v = it[1], wt = it[2];
//                 // consider a start node only if its reachable by src, ie dist[u]!=INT_MAX
//                 if(dist[u]!=INT_MAX && temp[v] > dist[u] + wt){
//                     temp[v] = dist[u] + wt;
//                 }
//             }
//             // copy temp to dist
//             copyVec(n,temp,dist);
//         }
        
//         if(dist[dst]!=INT_MAX){
//             return dist[dst];
//         }
//         return -1;
//     }
// };

// DIJKSTRA ALGO
class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // create adjacency list where adj[u] = {v,dist bw u and v}
        vector<vector<int>> graph[n];
        for(auto it:flights){
            int u=it[0], v=it[1], wt=it[2];
            graph[u].push_back({v,wt});
        }
        
        vector<int> dist(n,INT_MAX);
        vector<int> stops(n,INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // {dist of node from src, node, no of stops b/w src and node}
        pq.push({0,src,0});
        
        while(!pq.empty()){
            int currCost = pq.top()[0];
            int currNode = pq.top()[1];
            int currStops = pq.top()[2];
            pq.pop();
            
            if(stops[currNode] < currStops){
                continue;
            }
            
            stops[currNode] = currStops;
            
            if(dist[currNode]==INT_MAX){
                dist[currNode] = currCost;
            }
            
            // first instance of visiting a node will give min distance reqd
            if(currNode==dst){
                break;
            }
            
            // since we push currStops+1 in pq while traversing children, currStops+1<=k
            if(currStops>k){
                continue;
            }
            
            // add child nodes to priority queue
            for(auto it:graph[currNode]){
                int child=it[0], wt=it[1];
                int new_cost = currCost + wt;
                pq.push({new_cost,child,currStops+1});
            }
        }
        
        if(dist[dst]!=INT_MAX){
            return dist[dst];
        }
        return -1;
    }
};