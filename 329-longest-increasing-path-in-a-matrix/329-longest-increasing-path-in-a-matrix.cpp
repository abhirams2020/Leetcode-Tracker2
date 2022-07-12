// METHOD 1 : MEMOIZATION DP WITH INDEX i AND j AS PARAMETERS
// TABULATION METHOD COMPLICATED. NO NEED
class Solution {
public:
    int m,n;
    int dp[201][201];
    
    int moves[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    
    bool isValidIndex(int new_i, int new_j){
        return new_i>=0 && new_j>=0 && new_i<m && new_j<n;
    }
    
    int solve(vector<vector<int>>& matrix, int i, int j){
        // max possible length from curr = 1 + max(left,right,up,down)
        if(i<0 || j<0 || i>=m || j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int maxLen = 1;
        for(auto move:moves){
            int new_i = i+move[0], new_j = j+move[1];
            if(isValidIndex(new_i,new_j) && matrix[new_i][new_j]>matrix[i][j]){
                maxLen = max(maxLen, 1 + solve(matrix,new_i,new_j));
            }
        }
        return dp[i][j] = maxLen;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        memset(dp,-1,sizeof(dp));
        int ans = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = max(ans, solve(matrix,i,j));
            }
        }
        return ans;
    }
};