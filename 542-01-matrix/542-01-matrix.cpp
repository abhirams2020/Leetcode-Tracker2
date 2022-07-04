class Solution {
public:
//     // Using seperate matrix to return answer - O(m*n) space
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int m = mat.size();
//         int n = mat[0].size();
        
//         // -1 means not visited
//         vector<vector<int>> res(m, vector<int> (n,-1));
        
//         queue<pair<int,int>> q;
        
//         // add all 0 cells to queue
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(mat[i][j]==0){
//                     res[i][j] = 0;
//                     q.push({i,j});
//                 }
//             }
//         }
        
//         vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        
//         // since we added all 0 cells, for next cells distance from 0 will be 1. after each level increment dist
//         int dist = 1;
        
//         while(!q.empty()){
//             int qSize = q.size();
//             // qSize elements in queue is same level. ie. dist from nearest 0 is same. similar to level order traversal
//             for(int i=0;i<qSize;i++){
//                 int x = q.front().first;
//                 int y = q.front().second;
//                 q.pop();
//                 for(auto it:dir){
//                     int new_x = x + it[0];
//                     int new_y = y + it[1];
//                     if(new_x>=0 && new_y>=0 && new_x<m && new_y<n && res[new_x][new_y]==-1){
//                         q.push({new_x, new_y});
//                         // res[new_x][new_y] = 1 + res[x][y];
//                         res[new_x][new_y] = dist;
//                     }
//                 }
//             }
//             // after each level, distance from 0 will increase by 1
//             dist++;
//         }
        
//         return res;
//     }
    
    
    // Using same matrix to return answer - O(1) space
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        queue<pair<int,int>> q;
        
        // -1 means not visited
        // in original matrix, mark all non zero cells as not visited and add 0 cells to queue
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
                else {
                    mat[i][j] = -1;
                }
            }
        }
        
        vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        
        int dist = 1;
        
        while(!q.empty()){
            int qSize = q.size();
            // add cells of next level to queue. for each level distance = dist. after a level increment dist.
            for(int i=0;i<qSize;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(auto it:dir){
                    int new_x = x + it[0];
                    int new_y = y + it[1];
                    if(new_x>=0 && new_y>=0 && new_x<m && new_y<n && mat[new_x][new_y]==-1){
                        q.push({new_x, new_y});
                        mat[new_x][new_y] = dist;
                    }
                }
            }
            dist++;
        }
        
        return mat;
    }
};