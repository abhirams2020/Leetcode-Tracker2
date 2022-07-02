class Solution {
public:
    using pii = pair<int,int>;
    
    vector<vector<int>> adj;
    
    // find min Cost by forming minimum spanning tree using Prim's algo
    int minCost(int src){
        int N = adj.size();
        // key[i] = dist of i from parent[i]
        vector<int> parent(N), key(N,INT_MAX);
        vector<bool> MST(N,false);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0,src});
        parent[src] = -1;
        key[src] = 0;
        
        while(!pq.empty()){
            int curr = pq.top().second;
            pq.pop();
            MST[curr] = true;
            for(int child=0;child<N;child++){
                if(MST[child]==false && adj[curr][child]!=INT_MAX && key[child] > adj[curr][child]){
                    key[child] = adj[curr][child];
                    parent[child] = curr;
                    pq.push({key[child], child});
                }
            }
        }
        
        int sum = 0;
        for(auto i:key){
            sum+=i;
        }
        
        return sum;
    }
    
    int findDist(vector<vector<int>> &points, int i, int j){
        return abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        adj.resize(points.size(), vector<int> (points.size(), INT_MAX));
        
        // create adjacency list with weight
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int dist = findDist(points, i, j);
                // int dist = 0;
                adj[i][j] = dist;
                adj[j][i] = dist;
            }
        }
        
        return minCost(0);
    }
};