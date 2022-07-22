class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // q has indexes of possible answers
        int n = gas.size();
        queue<int> q;
        for(int i=0;i<n;){
            // at starting startion, we need to move cost[i] to get from i to i+1
            // at station i, available fuel is gas[i]. if cost[i]>gas[i] no need to consider that
            if(gas[i]>=cost[i]){
                q.push(i);
                // after adding a valid start point, skip all consecutive points which have gas[i]>cost[i]
                // since i is valid and i to k is valid it means valid starting point could be i only.
                while(i<n && gas[i]>=cost[i]){
                    i++;
                }
            }
            else {
                i++;
            }
        }
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            int tempCurr = curr;
            int fuel = gas[curr] - cost[curr];
            curr = (curr+1)%n;
            while(true){
                if(fuel < 0){
                    break;
                }                
                if(curr == tempCurr){
                    return tempCurr;
                }

                fuel = fuel - cost[curr] + gas[curr];
                curr = (curr+1)%n;
            }
        }
        return -1;
    }
};