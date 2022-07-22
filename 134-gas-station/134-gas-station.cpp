/*
// adding possible start index to queue and check each one
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // q has indexes of possible answers
        int n = gas.size();
        // if solution exists, sum of gas >= sum of cost
        int totalGas=0, totalCost=0;
        for(int i=0;i<n;i++){
            totalGas += gas[i];
            totalCost += cost[i];
        }
        
        if(totalGas < totalCost){
            return -1;
        }
        
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
        
        // for every index in queue, check if it can complete the circuit
        while(!q.empty()){
            int start = q.front();
            q.pop();
            int i = start;
            // initially we are at index i and fuel is 0.
            int fuel = 0;
            while(true){
                // travel from i to i+1
                fuel = fuel - cost[i] + gas[i];
                // if fuel becomes 0 before reaching next station, break the loop
                if(fuel < 0){
                    break;
                }
                i = (i+1)%n;
                // if next station is starting station, return that index
                if(i == start){
                    return start;
                }
            }
        }
        return -1;
    }
};
*/

// from neetcode. if the cycle exists, from i to end, if we can travel it means i is start index
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // q has indexes of possible answers
        int n = gas.size();
        // if solution exists, sum of gas >= sum of cost
        int totalGas=0, totalCost=0;
        for(int i=0;i<n;i++){
            totalGas += gas[i];
            totalCost += cost[i];
        }
        
        if(totalGas < totalCost){
            return -1;
        }
        
        int start = 0;
        int fuel = 0;
        
        for(int i=0;i<n;i++){
            if(fuel<0){
                start = i;
                fuel = 0;
            }
            fuel = fuel + gas[i] - cost[i];
        }
        
        return start;
    }
};