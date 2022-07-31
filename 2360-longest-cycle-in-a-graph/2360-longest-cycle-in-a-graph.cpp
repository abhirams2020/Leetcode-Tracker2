class Solution {
public:
    vector<int> cycleLen;
    
    unordered_map<int,pair<int,int>> dp;
    
    pair<int,int> dfs(vector<int> &edges, int currNode, vector<int> &visited){
        if(dp.count(currNode)){
            return dp[currNode];
        }
        if(visited[currNode]==1){
            return {currNode,0};
        }
        if(visited[currNode]==2){
            return {-1,-1};
        }
        visited[currNode] = 1;
        int child = edges[currNode];
        if(child!=-1){
            auto it = dfs(edges, child, visited);
            if(it.first != -1){
                dp[currNode] = {it.first, it.second+1};
                return dp[currNode];
            }
        }
        visited[currNode] = 2;
        return {-1,-1};
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(edges,i,visited);
            }
        }
        // for(auto [k,v]:dp){
        //     cout<<k<<" : "<<v.first<<" "<<v.second<<"\n";
        // }
        int maxVal = INT_MIN;
        for(int i=0;i<n;i++){
            if(dp.count(i) && dp[i].first == i){
                maxVal = max(maxVal, dp[i].second);
            }
        }
        if(maxVal==INT_MIN){
            return -1;
        }
        return maxVal;
    }
};