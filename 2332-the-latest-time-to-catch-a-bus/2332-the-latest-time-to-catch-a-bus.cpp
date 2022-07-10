class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        unordered_set<int> passengerTime;
        vector<vector<int>> ans;
        
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        
        // add passenger times to a set. answer should not have same time as a passenger
        for(auto i:passengers){
            passengerTime.insert(i);
        }
        
        // for each bus, add passengers in it
        // ans[bus index] gives the list of passengers in it
        for(int i=0,k=0;i<buses.size();i++){
            int cap = capacity;
            vector<int> temp;
            while(k<passengers.size() && passengers[k]<=buses[i] && cap>0){
                temp.push_back(passengers[k]);
                cap--;
                k++;
            }
            ans.push_back(temp);
        }
        
        // from last bus, check till we find valid time
        for(int i=buses.size()-1;i>=0;i--){
            // if current bus is empty, return that bus time
            if(ans[i].size()==0){
                return buses[i];
            }
            // find a start and end range for the current bus
            // start time should be time of last person who boarded the previous bus
            // to find start time, go through passenger array and find the time just less than starting time of current bus
            int start = 0;
            for(int j=0;j<passengers.size() && passengers[j]<ans[i][0];j++){
                start = passengers[j];
            }
            // if bus capacity is not reached, end time should be bus time.
            // if capacity is reached, the last passenger time should be the end time. 
            // beyond that the new passengers cannot enter the bus.
            int end = buses[i];
            if(ans[i].size()==capacity){
                end = ans[i][capacity-1];
            }
            // in end to start+1 range, find last time which is not colliding with another passenger time
            for(int j=end;j>start;j--){
                if(passengerTime.count(j)==0){
                    return j;
                }
            }
        }
        
        return -1;
    }
};