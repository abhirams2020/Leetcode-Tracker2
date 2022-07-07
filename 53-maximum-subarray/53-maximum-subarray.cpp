class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxVal = INT_MIN;
        int currSum = -(1e4-1);
        for(auto i:nums){
            currSum = max(i, currSum+i);
            maxVal = max(currSum, maxVal);
        }
        return maxVal;
    }
};