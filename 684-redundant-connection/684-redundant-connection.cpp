class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    int findParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    
    void _union(int a, int b){
        int u = findParent(a);
        int v = findParent(b);
        if(u==v){
            return;
        }
        if(rank[u]<rank[v]){
            parent[u] = v;
        }
        else if(rank[v]<rank[u]){
            parent[v] = u;
        }
        else {
            rank[u]++;
            parent[v] = u;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=1;i<=n;i++){
            parent[i] = i;
        }
        vector<int> ans;
        for(auto it:edges){
            int u = it[0], v = it[1];
            if(findParent(u) == findParent(v)){
                ans = it;
            }
            _union(u,v);
        }
        return ans;
    }
};