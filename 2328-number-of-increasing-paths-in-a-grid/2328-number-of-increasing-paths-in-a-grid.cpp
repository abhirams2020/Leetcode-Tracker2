class Solution {
public:
    long long dp[1001][1001];
    int m,n;
    int mod = 1e9 + 7;
    long long solve(vector<vector<int>>& grid, int prev, int i, int j){
        if(i<0 || j<0 || i>=m || j>=n || prev>=grid[i][j]){
            return 0;
        }
        if(dp[i][j]!=-1){
            return (dp[i][j])%mod;
        }
        return dp[i][j] = (1 + solve(grid,grid[i][j],i-1,j) + solve(grid,grid[i][j],i+1,j) + solve(grid,grid[i][j],i,j+1) + solve(grid,grid[i][j],i,j-1)) % mod;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        m = grid.size();
        n = grid[0].size();
        int sum = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sum = (sum + solve(grid,0,i,j))%mod;
            }
        }
        return sum;
    }
};