class Solution {
public:
    // adj[curr station] gives next stations vector
    unordered_map<string, vector<string>> adj;
    
    // keep track of no of remaining times we can visited an edge [from,to]
    map<pair<string,string>, int> visitedEdge;
    
    vector<string> ans;
    
    // total no of edges we need to visit
    int noOfEdges;
    
    // check if a valid route is found. since we sorted the adjacency list, first result should be final answer
    bool foundRoute = false;
    
    void createGraph(vector<vector<string>>& tickets) {
        // to get lexicographically smallest result, either sort the adjacency list or sort the tickets pair and add to adj
        // for same station lexicographically smaller next station will be added first to adj[station] vector
        sort(tickets.begin(), tickets.end());
        
        for(auto it:tickets){
            string from = it[0];
            string to = it[1];
            visitedEdge[{from,to}]++;
            adj[from].push_back(to);
        }
    }
    
    void dfs(string curr, vector<string>& route){
        // if no more edges left to visit
        if(visitedEdge.size()==0){
            ans = route;
            foundRoute = true;
            return;
        }
        for(auto child:adj[curr]){
            if(foundRoute==false && visitedEdge.count({curr,child})){
                visitedEdge[{curr,child}]--;
                if(visitedEdge[{curr,child}]==0){
                    visitedEdge.erase({curr,child});
                }
                
                route.push_back(child);
                dfs(child,route);
                
                visitedEdge[{curr,child}]++;
                route.pop_back();
            }
        }
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // create adjacency list and add count of each edge to visitedEdge
        createGraph(tickets);
        
        noOfEdges = tickets.size();
        
        vector<string> route;
        
        // start station should be JFK for all routes
        route.push_back("JFK");
        // do dfs starting from JFK
        dfs("JFK", route);
        
        return ans;
    }
};