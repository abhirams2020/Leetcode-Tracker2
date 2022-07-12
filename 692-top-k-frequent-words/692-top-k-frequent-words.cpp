/*
// METHOD 1 : USING VECTOR AND CUSTOM SORT
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
*/

// METHOD 2 : USING PRIORITY QUEUE AND CUSTOM SORT
using pis = pair<int,string>;

// when custom comparator for priority returns true, it means no swap. Compare for pq is opposite to compare for vector.
// eg for order in pq -> TOP : [ [1,leetcode], [1,coding], [2,love], [2,i] ]
// when we pop from pq, lowest freq elements should pop and for same freq, highest lexicographical string should pop
class comp {
public:
    bool operator()(pis &a, pis &b){
        if(a.first==b.first){
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto s:words){
            mp[s]++;
        }
        priority_queue<pis, vector<pis>, comp> pq;
        // add {freq,string} to pq
        for(auto [key,val]:mp){
            pq.push({val,key});
            // maintain pq size = k
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<string> ans;
        // push the elements of pq to ans
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        // since pq is minheap, the order will be reverse
        reverse(ans.begin(),ans.end());
        return ans;
    }
};