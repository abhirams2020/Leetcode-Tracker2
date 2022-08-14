/*
// TAKE TOP 2 ELEMENTS AND ADD ALTERNATIVELY
class Solution {
public:
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
        
        string ans;
        // keep taking top 2 freq elements from maxh and add to ans
        while(maxh.size() > 1){ // 2 elements required for getting top 2
            auto top1 = maxh.top();
            maxh.pop();
            auto top2 = maxh.top();
            maxh.pop();
            // add the top letters in order
            ans += top1.second;
            ans += top2.second;
            // after adding, if any letters are left, add back to maxheap
            if(top1.first > 1){
                maxh.push({top1.first-1, top1.second});
            }
            if(top2.first > 1){
                maxh.push({top2.first-1, top2.second});
            }
        }
        // if any element left in maxheap and freq = 1, add to ans. if freq more than 1, return ""
        if(!maxh.empty()){
            auto it = maxh.top();
            maxh.pop();
            if(it.first > 1){
                return "";
            }
            ans += it.second;
        }
        return ans;
    }
};
*/

// SIMILAR TO TASK SCHEDULER WITH COOLDOWN = 1
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