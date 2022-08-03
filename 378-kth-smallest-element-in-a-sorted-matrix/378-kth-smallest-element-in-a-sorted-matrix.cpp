class Solution {
public:
    // fn to return no of elements <= n in nums
    int upperBound(vector<int> &nums, int target){
        int len = nums.size();
        // check 1st element greater than target
        if(nums[0]>target){
            return 0;
        }
        // check last element less than target
        if(nums[len-1]<target){
            return len;
        }
        int lo=0, hi=len-1;
        while(hi-lo>1){
            int mid = lo+(hi-lo)/2;
            if(nums[mid]>target){
                hi = mid-1;
            }
            else {
                lo = mid;
            }
        }
        if(nums[hi]<=target){
            return hi+1;
        }
        if(nums[lo]<=target){
            return lo+1;
        }
        return len;
    }
    
    // for finding kth smallest, do binary search on range of values and check no of elements <= val
    // finding first element with no of elements >= k. that will be kth smallest number
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int hi = INT_MIN, lo = INT_MAX;
        // find max and min values in the matrix to find hi and lo for binary search
        for(auto v:matrix){
            for(auto i:v){
                lo = min(lo, i);
                hi = max(hi, i);
            }
        }
        
        while(hi-lo>1){
            int mid = lo+(hi-lo)/2;
            int lessOrEqualCount = 0;
            for(int i=0;i<matrix.size();i++){
                lessOrEqualCount += upperBound(matrix[i], mid);
            }
            if(lessOrEqualCount < k){
                lo = mid+1;
            }
            else {
                hi = mid;
            }
        }
        
        int countLo = 0, countHi = 0;
        for(int i=0;i<matrix.size();i++){
            countLo += upperBound(matrix[i], lo);
            countHi += upperBound(matrix[i], hi);
        }
        
        if(countLo >= k){
            return lo;
        }
        
        if(countHi >= k){
            return hi;
        }
        
        return 0;
    }
};