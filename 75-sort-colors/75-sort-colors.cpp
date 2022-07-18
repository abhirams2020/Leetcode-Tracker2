class Solution {
public:
    void sortColors(vector<int>& arr) {
        // at every instance after swapping,
        // 0 to l-1 will have 0
        // l to i will have 1
        // r+1 to n-1 will have 2
        int l=0, r=arr.size()-1;
        // since we dont move i when arr[i]==2, it is sure that if we are at i, 0 to i-1 will not contain 2.
        // if arr[i]==0, we swap 0 with 1 at index l. so for arr[i]==0 and arr[i]==1, do i++.
        for(int i=0; i<=r; ){
            if(arr[i]==0){
                swap(arr[i],arr[l]);
                l++;
                i++;
            }
            else if(arr[i]==1){
                i++;
            }
            else if(arr[i]==2){
                swap(arr[i],arr[r]);
                r--;
            }
        }
    }
};