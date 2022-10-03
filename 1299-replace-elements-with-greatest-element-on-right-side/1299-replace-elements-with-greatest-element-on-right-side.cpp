class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxSoFar = -1;
        for(int i=n-1;i>=0;i--){
            int maxToRight = maxSoFar;
            if(arr[i] > maxSoFar){
                maxSoFar = arr[i];
            }
            arr[i] = maxToRight;
        }
        return arr;
    }
};