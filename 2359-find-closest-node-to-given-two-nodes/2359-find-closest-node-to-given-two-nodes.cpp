class Solution {
public:
    unordered_map<int,int> mp[3];
    vector<vector<bool>> visited;
    
    void dfs(vector<int> &edges, int currNode, int currDist, int parent){
        mp[parent][currNode] = currDist;
        visited[parent][currNode] = true;
        if(edges[currNode]!=-1 && visited[parent][edges[currNode]]==false){
            int child = edges[currNode];
            dfs(edges,child,currDist+1,parent);
        }
        visited[parent][currNode] = false;
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        // similar to rotten oranges. time taken to rot all oranges = dist between both
        int n = edges.size();
        visited.resize(3, vector<bool> (n+1,false));
        dfs(edges,node1,0,1);
        dfs(edges,node2,0,2);
        // for(int i=1;i<=2;i++){
        //     for(auto [k,v]:mp[i]){
        //         cout<<k<<","<<v<<" ";
        //     }
        //     cout<<"\n";
        // }
        int minNode = -1;
        int minDist = INT_MAX;
        for(int i=0;i<edges.size();i++){
            if(mp[1].count(i) && mp[2].count(i)){
                int currMax = max(mp[1][i],mp[2][i]);
                // cout<<currMax<<"\n";
                if(minDist > currMax){
                    minNode = i;
                    minDist = max(mp[1][i],mp[2][i]);
                }
            }
        }
        if(minDist==INT_MAX){
            return -1;
        }
        return minNode;
    }
};