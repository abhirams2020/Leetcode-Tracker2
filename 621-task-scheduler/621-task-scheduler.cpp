class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        
        for(auto i:tasks){
            mp[i]++;
        }
        
        priority_queue<int> maxh;
        queue<pair<int,int>> q;
        
        for(auto [k,v]:mp){
            maxh.push(v);
        }
        
        int time = 0;
        
        // exit loop only when both maxh and q is empty
        while(!maxh.empty() || !q.empty()){
            while(!q.empty() && q.front().second<=time){
                maxh.push(q.front().first);
                q.pop();
            }
            
            if(!maxh.empty()){
                int count = maxh.top();
                maxh.pop();
                count--;
                if(count>0){
                    q.push({count,time+n+1});
                }
            }
            
            time++;
        }
        
        return time;
    }
};