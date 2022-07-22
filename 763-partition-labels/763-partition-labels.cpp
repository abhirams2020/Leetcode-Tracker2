/*
class Solution {
public:
    // check if there is any intersection between map a and map b
    bool intersection(unordered_map<char,int> &a, unordered_map<char,int> &b){
        for(auto [k,v]:a){
            if(b.count(k)){
                return true;
            }
        }
        return false;
    }
    
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char,int> mp;
        // initialise mp as set of all elements in the array
        for(auto c:s){
            mp[c]++;
        }
        // we start from left and move r till we find l to r-1 doesnt have common element in r to n-1 range
        // while moving r, reduce that element from mp and add it to currMap till we find no intersection.
        // the point when loop stops, it means l to r-1 have no intersection with r to n-1 range. add to ans
        int l=0, r=0;
        while(r<s.length()){
            unordered_map<char,int> currMap;
            while(r<s.length() && (currMap.size()==0 || intersection(currMap,mp)==true)){
                currMap[s[r]]++;
                mp[s[r]]--;
                if(mp[s[r]]==0){
                    mp.erase(s[r]);
                }
                r++;
            }
            ans.push_back(r-l);
            l = r;
        }
        
        return ans;
    }
};
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]] = i;
        }
        
        int l=0, r=0;
        while(r<s.length()){
            int lastIdx = -1;
            while(lastIdx==-1 || r<=lastIdx){
                lastIdx = max(lastIdx, mp[s[r]]);
                r++;
            }
            ans.push_back(r-l);
            l =  r;
        }
        
        return ans;
    }
};