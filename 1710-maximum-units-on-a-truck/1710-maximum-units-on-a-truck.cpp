class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int maxVal = 0;
        for(auto it:boxTypes){
            int boxCount = min(it[0], truckSize);
            maxVal += it[1] * boxCount;
            truckSize -= boxCount;
        }
        return maxVal;
    }
};