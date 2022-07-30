class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int maxVal = 0, currSize = 0;
        for(int i=0; i<boxTypes.size(); i++){
            for(int j=0; j<boxTypes[i][0]; j++){
                if(currSize < truckSize){
                    maxVal += boxTypes[i][1];
                    currSize++;
                }
                else {
                    return maxVal;
                }
            }
        }
        return maxVal;
    }
};