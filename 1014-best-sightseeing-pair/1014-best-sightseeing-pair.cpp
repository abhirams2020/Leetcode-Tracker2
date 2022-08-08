class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        // we need to find max of val[i]+i + val[j]-j such that i<j
        // we can store all the val[i] + i before j and find the max out of those
        // or after visiting each index, store its val[i]+i value if it is greater than previous ones
        
        int maxVal = INT_MIN; // to store max value of val[i]+i + val[j]-j
        
        int prevMaxSum = INT_MIN; // max value of val[i] + i found so far
        
        // for every index in arr, check if val[curr] - curr + prevMaxSum greater than maxVal so far
        for(int i=0;i<values.size();i++){
            if(prevMaxSum != INT_MIN){
                maxVal = max(maxVal, prevMaxSum + values[i]-i);
            }
            prevMaxSum = max(prevMaxSum, values[i] + i);
        }
        
        return maxVal;
    }
};