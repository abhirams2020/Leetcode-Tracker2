class Solution {
public:
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    bool isValid(vector<vector<int>> &grid, int row, int col){
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size()){
            return false;
        }
        if(grid[row][col]!=1){
            return false;
        }
        return true;
    }
    
    int dfs(vector<vector<int>> &grid, int row, int col) {
        int area = 1;
        for(vector<int> &dir:directions){
            int new_i = row+dir[0], new_j = col+dir[1];
            if(isValid(grid, new_i, new_j)){
                grid[new_i][new_j] = 2;
                area += dfs(grid, new_i, new_j);
            }
        }
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    grid[i][j] = 2;
                    int currArea = dfs(grid,i,j);
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        
        return maxArea;
    }
};