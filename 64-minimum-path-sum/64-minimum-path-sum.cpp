class Solution {
public:
    int dp[201][201];
    vector<vector<int>> dir = {{0,1}, {1,0}};
    int INF = 1e6;
    
    int dfs(vector<vector<int>> &grid, int i, int j, int m, int n){
        if(i==m-1 && j==n-1) 
            return grid[i][j];
        if(i>=m || j>=n){
            return INF;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int minVal = INF;
        for(auto it:dir){
            int new_i = i + it[0], new_j = j + it[1];
            minVal = min(minVal, dfs(grid,new_i,new_j,m,n));
        }
        return dp[i][j] = grid[i][j] + minVal;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int m = grid.size(), n = grid[0].size();
        int minPath = dfs(grid,0,0,m,n);
        return minPath;
    }
};