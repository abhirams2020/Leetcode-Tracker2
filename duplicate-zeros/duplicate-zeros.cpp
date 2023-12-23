class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,0);
        int p1=0, p2=0;
        while(p2 < n){
            if(arr[p1] == 0){
                p1 += 1;
                p2 += 2;
            }
            else {
                ans[p2] = arr[p1];
                p1 += 1;
                p2 += 1;
            }
        }
        arr = ans;
    }
};