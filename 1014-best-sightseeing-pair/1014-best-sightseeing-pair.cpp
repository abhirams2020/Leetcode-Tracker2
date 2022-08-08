class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // we need to find max of val[i]+i + val[j]-j such that i<j
        // we can store all the val[i] + i before j and find the max out of those using priority queue
        priority_queue<int> add; // values are val[i] + i
        
        int maxVal = INT_MIN;
        
        for(int i=0;i<values.size();i++){
            if(!add.empty()){
                maxVal = max(maxVal, add.top() + values[i]-i);
            }
            add.push({values[i] + i});
        }
        
        return maxVal;
    }
};