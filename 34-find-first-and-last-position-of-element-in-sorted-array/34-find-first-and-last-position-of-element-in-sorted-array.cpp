class Solution {
public:
    int lastPos (vector<int>& nums, int target){
        if(nums.size()==0){
            return -1;
        }        
        int n = nums.size();
        int lo=0, hi=n-1;
        // binary search and reduce search space to 2 (lo,hi)
        while(hi-lo>1){
            int mid = lo + (hi - lo) / 2;
            // split search space into l to mid and mid+1 to hi
            // if nums[mid]==target, we have to include in search space and go right
            if(nums[mid] > target){
                hi = mid-1;
            }
            else {
                lo = mid;
            }
        }        
        // since we want last occurance, check from right to left
        if(nums[hi]==target){
            return hi;
        }
        if(nums[lo]==target){
            return lo;
        }
        return -1;
    }
    
    int firstPos (vector<int>& nums, int target){
        if(nums.size()==0){
            return -1;
        }
        int n = nums.size();
        int lo=0, hi=n-1;
        // binary search and reduce search space to 2 (lo,hi) [from luv video]
        while(hi-lo>1){
            int mid = lo + (hi - lo) / 2;
            // split search space into l to mid and mid+1 to hi
            // if nums[mid]==target, we have to include in search space and go left
            if(nums[mid] < target){
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        // since we want first occurance, check from left to right
        if(nums[lo]==target){
            return lo;
        }
        if(nums[hi]==target){
            return hi;
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstPos(nums,target);
        int last = lastPos(nums,target);
        return {first,last};
    }
};