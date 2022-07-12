// USING PRIORITY QUEUE
class Solution {
public:
    // sort in descending order of frequency. for same frequency strings are sorted in ascending order.
    static bool comp(pair<int,string> &a, pair<int,string> &b){
        if(a.first==b.first){
            return a.second < b.second;
        }
        return a.first>b.first;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto s:words){
            mp[s]++;
        }
        vector<pair<int,string>> pq;
        for(auto [key,val]:mp){
            pq.push_back({val,key});
        }
        sort(pq.begin(),pq.end(),comp);
        vector<string> ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq[i].second);
        }
        return ans;
    }
};