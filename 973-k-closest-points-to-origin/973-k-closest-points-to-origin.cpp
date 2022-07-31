class Solution {
public:
    int dist(int x, int y){
        return x*x + y*y;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> pq;
        for(auto it:points){
            pq.push({dist(it[0],it[1]), it[0], it[1]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(k--){
            ans.push_back({pq.top()[1], pq.top()[2]});
            pq.pop();
        }
        return ans;
    }
};