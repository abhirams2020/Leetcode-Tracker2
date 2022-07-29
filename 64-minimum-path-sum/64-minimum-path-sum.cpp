class Solution {
public:
    int dp[201][201];
    vector<vector<int>> dir = {{0,1}, {1,0}};
    int INF = 1e6;
    
    bool isValid(int i, int j, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n){
            return false;
        }
        return true;
    }
    
    int dfs(vector<vector<int>> &grid, int i, int j, int m, int n){
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int minVal = INF;
        for(auto it:dir){
            int new_i = i + it[0], new_j = j + it[1];
            if(isValid(new_i,new_j,m,n)){
                minVal = min(minVal, grid[i][j] + dfs(grid,new_i,new_j,m,n));
            }
        }
        return dp[i][j] = minVal;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int m = grid.size(), n = grid[0].size();
        int minPath = dfs(grid,0,0,m,n);
        return minPath;
    }
};