class Solution {
public:
    bool intersection(unordered_map<char,int> &a, unordered_map<char,int> &b){
        for(auto [k,v]:a){
            if(b.count(k)){
                return true;
            }
        }
        return false;
    }
    
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        for(auto c:s){
            mp[c]++;
        }
        vector<int> ans;
        // if(mp.size()==s.length()){
        //     ans.push_back(s.length());
        //     return ans;
        // }
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