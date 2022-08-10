class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> taskCount;
        for(auto task:tasks){
            taskCount[task]++;
        }
        // add task counts to a maxheap. any task in maxheap can be executed and add to waiting queue
        priority_queue<int> maxh;
        for(auto [task,count]:taskCount){
            maxh.push(count);
        }
        // maintain a waiting queue with values {taskcount, next valid time to run task}
        queue<pair<int,int>> q;
        
        int time = 0;
        
        while(!maxh.empty() || !q.empty()){
            // add all valid tasks in queue to maxh
            while(!q.empty() && q.front().second <= time){
                maxh.push(q.front().first);
                q.pop();
            }
            if(!maxh.empty()){
                int currCount = maxh.top();
                maxh.pop();
                // if this is last occurence of current task, no need to add in wait queue
                if(currCount>1){
                    q.push({currCount-1, time+n+1});
                }
            }
            time++;
        }
        
        return time;
    }
};