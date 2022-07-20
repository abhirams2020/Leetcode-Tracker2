class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // start with taking all rotten ones and add to queue
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int t = 0; // track time. for each level time++
        int time = 0;
        // do bfs using this queue
        vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            time = t; // when new level is reached, update the latest time
            int n = q.size();
            for(int i=0;i<n;i++){
                auto it = q.front();
                int x = it.first;
                int y = it.second;
                q.pop();
                for(auto dir:directions){
                    int new_x = x + dir[0];
                    int new_y = y + dir[1];
                    if(new_x>=0 && new_x<grid.size() && new_y>=0 && new_y<grid[0].size() && grid[new_x][new_y]==1){
                        grid[new_x][new_y] = 2;
                        q.push({new_x, new_y});
                    }
                }
            }
            t++;
        }
        
        // if any orange not rotten, return -1
        for(auto v:grid){
            for(auto i:v){
                if(i==1){
                    return -1;
                }
            }
        }
        
        return time;
    }
};