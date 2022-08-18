class Solution {
public:
    vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    
    void dfs(vector<vector<char>> &grid, int i, int j){
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size()){
            return;
        }
        if(grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';
        for(auto dir:directions){
            dfs(grid, i+dir[0], j+dir[1]);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};