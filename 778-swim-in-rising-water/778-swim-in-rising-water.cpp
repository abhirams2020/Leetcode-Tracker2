class Solution {
public:
    // position is invalid if it is out of bounds or has been visited before
    bool isValid(vector<vector<int>>& grid, vector<bool>& visited, int i, int j){
        int n = grid.size();
        if(i<0 || j<0 || i>=n || j>=n){
            return false;
        }
        if(visited[grid[i][j]]==true){
            return false;
        }
        return true;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int startNode = grid[0][0];
        int endNode = grid[n-1][n-1];
        priority_queue< vector<int> , vector<vector<int>> , greater<vector<int>> > pq;
        // there are elements from 0 to n*n-1 in the matrix. create vector of size n*n for visited array
        vector<bool> visited(n*n, false);
        vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        // pq = {node, max in path, i, j}
        pq.push({startNode,startNode,0,0});
        visited[startNode] = true;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int currNode = it[0];
            int currMax = it[1];
            int curr_i = it[2];
            int curr_j = it[3];
            
            if(currNode==endNode){
                return currMax;
            }
            
            // for a node, possible children (ie next position) will be in 4 directions
            // if the new position is valid, add the child to priority queue
            for(auto dir:directions){
                int new_i = curr_i + dir[0], new_j = curr_j + dir[1];
                if(isValid(grid, visited, new_i, new_j)){
                    int newNode = grid[new_i][new_j];
                    int newMax = max(currMax, grid[new_i][new_j]);
                    pq.push({newNode, newMax, new_i, new_j});
                    visited[grid[new_i][new_j]] = true;
                }
            }
        }
        
        return -1;
    }
};