class Solution {
public:
    
    int count = 0;
    
    // In merge function, left subarray will have index lower than right subarray
    // so we can compare elements in both subarrays before sorting
    void merge(vector<int> &arr, int l, int mid, int r) {
        int n = r-l+1; // size of parition
        vector<int> temp(n);
        // int temp[n];
        int ptr = 0;
        int left=l, right=mid+1;
        
        // l to mid and mid+1 to r is sorted in ascending order
        // so if any i in left is greater than j in right, means mid+1 to j forms pair with i
        int j = mid+1;
        for(int i=l;i<=mid;i++){
            while(j<=r && arr[i]>2*(long long)arr[j]){
                j++;
            }
            count += j-(mid+1);
        }
        
        while(left<=mid && right<=r){
            if(arr[left]<=arr[right]){
                temp[ptr] = arr[left];
                left++;
            }
            else {
                temp[ptr] = arr[right];
                right++;
            }
            ptr++;
        }
        
        while(left<=mid){
            temp[ptr] = arr[left];
            left++;
            ptr++;
        }
        while(right<=r){
            temp[ptr] = arr[right];
            right++;
            ptr++;
        }
        for(int i=0;i<n;i++){
            arr[l+i] = temp[i];
        }
    }
    
    void mergesort(vector<int> &arr, int  l, int  r){
        if(l>=r){
            return;
        }
        int mid = l + (r-l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergesort(nums,0,n-1);
        return count;
    }
};