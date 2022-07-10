class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        unordered_set<int> pSet;
        vector<vector<int>> ans;
        
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        
        for(auto it:passengers){
            pSet.insert(it);
        }
        
        
        int ptr=0;
        
        for(int k=0;k<buses.size();k++){
            int cap = capacity;
            vector<int> temp;
            while(ptr<passengers.size() && passengers[ptr]<=buses[k] && cap>0){
                temp.push_back(passengers[ptr]);
                cap--;
                ptr++;
            }
            ans.push_back(temp);
        }
        
        // cout<<"\n";
        // for(auto v:ans){
        //     for(auto i:v){
        //         cout<<i<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n";
        
        for(int i=buses.size()-1;i>=0;i--){
            if(ans[i].size()==0){
                return buses[i];
            }
            int start = 0;
            for(int j=0;j<passengers.size() && passengers[j]<ans[i][0];j++){
                start = passengers[j];
            }
            int end = buses[i];
            if(ans[i].size()==capacity){
                end = ans[i][capacity-1];
            }
            for(int j=end;j>start;j--){
                if(pSet.count(j)==0){
                    return j;
                }
            }
        }
        
        return -1;
    }
};