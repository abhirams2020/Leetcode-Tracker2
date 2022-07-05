// // BELLMAN FORD ALGO (MEDIUM)
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

// // DIJKSTRA ALGO (HARD)
// class Solution2 {
// public:
    
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         // create adjacency list where adj[u] = {v,dist bw u and v}
//         vector<vector<int>> graph[n];
//         for(auto it:flights){
//             int u=it[0], v=it[1], wt=it[2];
//             graph[u].push_back({v,wt});
//         }
//         // dist[] stores minimum distance required to reach node from src.
//         vector<int> dist(n,INT_MAX);
//         // stops[] stores minimum no of stops required to reach node from src.
//         vector<int> stops(n,INT_MAX);
//         // pq => {dist of node from src, node, no of stops b/w src and node}
//         priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
//         pq.push({0,src,0});
        
//         while(!pq.empty()){
//             auto it = pq.top();
//             int currCost = it[0], currNode = it[1], currStops = it[2];
//             pq.pop();
            
//             // update the dist[] with minimum distance to reach the node
//             // first time visiting a node will be the minimum distance from src to node
//             if(dist[currNode]==INT_MAX){
//                 dist[currNode] = currCost;
//             }
            
//             // if destination is reached, no more bfs is required
//             if(currNode==dst){
//                 break;
//             }
            
//             // we should also consider paths with lesser stops than current no of stops 
//             // in case the earlier result runs out of stops before reaching destination
//             // so consider path with minimum distance and also path with minimum no of stops
//             if(stops[currNode] < currStops){
//                 continue;
//             }
            
//             stops[currNode] = currStops;
            
//             // since we push currStops+1 in pq while traversing children, currStops+1<=k
//             if(currStops>k){
//                 continue;
//             }
            
//             // add child nodes to priority queue
//             for(auto it:graph[currNode]){
//                 int child=it[0], wt=it[1];
//                 int new_cost = currCost + wt;
//                 pq.push({new_cost,child,currStops+1});
//             }
//         }
        
//         if(dist[dst]!=INT_MAX){
//             return dist[dst];
//         }
//         return -1;
//     }
// };

// MODIFIED DIJKSTRA ALGO (HARD) - MORE READABLE
class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // create adjacency list where adj[u] = {v,dist bw u and v}
        vector<vector<int>> graph[n];
        for(auto it:flights){
            int u=it[0], v=it[1], wt=it[2];
            graph[u].push_back({v,wt});
        }
        
        // minCost[n][k] gives minimum cost for reaching a node n in k steps
        // we need to consider steps since if one edge is having very long distance but less stops, 
        // path with more number of steps is taken. if same node and same steps but different path, minimum is taken
        vector<vector<int>> minCost(n+1, vector<int> (k+2, INT_MAX));
        
        // no of stops between src and dst = k. so total no of stops from src = k+1.
        // so priority queue can have values from 0 to k+1.
        int maxStops = k+1;
        
        // pq => {dist of node from src, node, no of stops b/w src and node}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0,src,0});
        
        
        while(!pq.empty()){
            auto it = pq.top();
            int currCost = it[0], currNode = it[1], currStops = it[2];
            pq.pop();
            
            if(currNode == dst){
                return currCost;
            }
            
            // ignore if we found a node with better cost path before
            if(currCost > minCost[currNode][currStops]){
                continue;
            }
            
            // add child nodes to priority queue
            for(auto it:graph[currNode]){
                int child=it[0], wt=it[1];
                int childCost = currCost + wt;
                int childStops = currStops + 1;
                // stops in pq can be maximum value of maxStops
                if(childStops <= maxStops){
                    // if this path is better than previous ones, add it to pq
                    if(minCost[child][childStops] > childCost){
                        minCost[child][childStops] = childCost;
                        pq.push({childCost, child, childStops});
                    }
                }
            }
        }
        
        return -1;
    }
};