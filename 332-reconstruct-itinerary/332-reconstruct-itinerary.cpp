class Solution {
public:
    // adj[curr station] gives next stations vector in lexicographical order
    unordered_map<string, vector<string>> adj;
    
    // keep track of no of remaining no of times we can visit an edge [from,to]
    map<pair<string,string>, int> edgeCount;
    
    vector<string> ans;
    
    // check if a valid route is found. since we sorted the adjacency list, first result should be final answer
    bool foundValidRoute = false;
    
    void createGraph(vector<vector<string>>& tickets) {
        // to get lexicographically smallest result, either sort the adjacency list or sort the tickets pair and add to adj
        // for same station lexicographically smaller next station will be added first to adj[station] vector
        sort(tickets.begin(), tickets.end());
        
        for(auto it:tickets){
            string from = it[0];
            string to = it[1];
            edgeCount[{from,to}]++; // add edges to edgeCount which counts no of times an edge can be visited
            adj[from].push_back(to);
        }
    }
    
    void dfs(string curr, vector<string>& route){
        // if no more edges left to visit
        if(edgeCount.size()==0){
            ans = route;
            foundValidRoute = true;
            return;
        }
        for(auto child:adj[curr]){
            // if valid route has not been found and edge {curr,child} can be visited, add child to route and dfs
            if(foundValidRoute==false && edgeCount.count({curr,child})){
                edgeCount[{curr,child}]--;
                if(edgeCount[{curr,child}]==0){
                    edgeCount.erase({curr,child});
                }
                
                route.push_back(child);
                dfs(child,route);
                
                // backtracking
                edgeCount[{curr,child}]++;
                route.pop_back();
            }
        }
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // create adjacency list and add count of each edge to visitedEdge
        createGraph(tickets);
        
        vector<string> route;
        
        // start station should be JFK for all routes
        route.push_back("JFK");
        // do dfs starting from JFK
        dfs("JFK", route);
        
        return ans;
    }
};