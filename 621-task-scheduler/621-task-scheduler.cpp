class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0){
            return tasks.size();
        }
        
        unordered_map<char,int> mp;
        // count occurrence of all tasks
        for(auto i:tasks){
            mp[i]++;
        }
        // maxh stores the occurrence of each task ready to be done
        priority_queue<int> maxh;
        // q stores the tasks which is in cooldown
        queue<pair<int,int>> q;
        
        // first push all tasks count to maxh
        for(auto [k,v]:mp){
            maxh.push(v);
        }
        
        int time = 0;
        
        // exit loop only when both maxh and q is empty
        while(!maxh.empty() || !q.empty()){
            // from q, push every valid task (t<=currtime) to maxh
            while(!q.empty() && q.front().second<=time){
                maxh.push(q.front().first);
                q.pop();
            }
            
            // from maxh, always pick task with most frequency and add to queue after reducing freq by 1
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