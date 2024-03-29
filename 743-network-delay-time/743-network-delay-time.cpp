class Solution {
public:
    // typedef pair<int,int> pii;
    // using preferred in c++
    using pii = pair<int,int>;
        
    // dmap [node] gives {neighbour, distance}
    vector<vector<pii>> dmap;
    
    // we need to reach all nodes with min distance. so use dijkstra algo
    // dijkstra is like bfs with priority queue with {dist,node} values
    int dijkstra(int size, int source){
        int time = 0;
        vector<int> dist(size+1,INT_MAX);
        // priority queue elements are {distance from start, node}
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,source});
        dist[source] = 0;
        while(!pq.empty()){
            int curr = pq.top().second;
            pq.pop();
            for(auto [n,wt]:dmap[curr]){
                // if dist from curr to n is shortest path found so far, push to pq
                if(dist[curr] + wt < dist[n]){
                    dist[n] = dist[curr] + wt;
                    pq.push({dist[n],n});
                }
            }
        }
        // check if it is possible to reach all point from k
        for(int i=1;i<=size;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
        }
        // if possible to reach, find max time taken to reach all nodes
        for(int i=1;i<=size;i++){
            time = max(time,dist[i]);
        }
        return time;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        dmap.resize(n+1);
        for(auto v:times){
            dmap[v[0]].push_back({v[1],v[2]});
        }
        return dijkstra(n,k);
    }
};