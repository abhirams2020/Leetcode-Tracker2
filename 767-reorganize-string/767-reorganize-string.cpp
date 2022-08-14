class Solution {
public:
    // this problem is similar to task scheduler with cooldown = 1. if mp becomes empty at any point, return ""
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(auto &c:s){
            mp[c]++;
        }
        
        // add {count,char} to a priority queue
        priority_queue<pair<int,char>> maxh;
        for(auto &[k,v]:mp){
            maxh.push({v,k});
        }
        
        queue<pair<int,pair<int,char>>> q; // queue contains {next valid time, {count, char}}
        
        string ans;
        int t = 0;
        
        while(!maxh.empty() || !q.empty()){
            // add all valid elements from q to maxh
            while(!q.empty() && q.front().first <= t){
                auto it = q.front().second;
                q.pop();
                maxh.push(it);
            }
            if(maxh.empty()){
                return "";
            }
            auto curr = maxh.top();
            maxh.pop();
            
            int currCount = curr.first;
            char currChar = curr.second;
            ans.push_back(currChar);
            
            // add {count-1,char} to q with next valid time = t + 2
            if(currCount-1 != 0){
                q.push({t+2,{currCount-1,currChar}});
            }
            t++;
        }
        return ans;
    }
};