class Solution {
public:
    int m,n;
    vector<vector<int>> dp;
    
    // // GOING TO ALL DIRECTIONS FROM CURR
    // int solve(vector<vector<int>>& matrix, int i, int j){
    //     // max possible length from curr = 1 + max(left,right,up,down)
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     int len = 0;
    //     if(i>0 && matrix[i-1][j]>matrix[i][j]){
    //         len = max(len, solve(matrix,i-1,j));
    //     }
    //     if(i<m-1 && matrix[i+1][j]>matrix[i][j]){
    //         len = max(len, solve(matrix,i+1,j));
    //     }
    //     if(j>0 && matrix[i][j-1]>matrix[i][j]){
    //         len = max(len, solve(matrix,i,j-1));
    //     }
    //     if(j<n-1 && matrix[i][j+1]>matrix[i][j]){
    //         len = max(len, solve(matrix,i,j+1));
    //     }
    //     return dp[i][j] = 1 + len;
    // }
    
    int moves[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    
    bool isValidIndex(int new_i, int new_j){
        return new_i>=0 && new_j>=0 && new_i<m && new_j<n;
    }
    
    // USING DIRECTION MATRIX TO TRAVERSE FROM CURR
    int solve(vector<vector<int>>& matrix, int i, int j){
        // max possible length from curr = 1 + max(left,right,up,down)
        if(i<0 || j<0 || i>=m || j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int len = 0;
        for(auto move:moves){
            int new_i = i+move[0], new_j = j+move[1];
            if(isValidIndex(new_i,new_j) && matrix[new_i][new_j]>matrix[i][j]){
                len = max(len, solve(matrix,new_i,new_j));
            }
        }
        return dp[i][j] = 1 + len;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        dp.resize(m+1, vector<int> (n+1, -1));
        int ans = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = max(ans, solve(matrix,i,j));
            }
        }
        return ans;
    }
};