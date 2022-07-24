class Solution {
public:
    int upperBound (vector<int>& nums, int target){
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
            if(nums[mid] <= target){
                lo = mid;
            }
            else {
                hi = mid-1;
            }
        }
        // cout<<nums[lo]<<" "<<nums[hi]<<"\n";
        if(nums[hi]==target){
            return hi;
        }
        if(nums[lo]==target){
            return lo;
        }
        return -1;
    }
    
    int lowerBound (vector<int>& nums, int target){
        if(nums.size()==0){
            return -1;
        }
        int n = nums.size();
        int lo=0, hi=n-1;
        // binary search and reduce search space to 2 (lo,hi)
        while(hi-lo>1){
            int mid = lo + (hi - lo) / 2;
            // split search space into l to mid and mid+1 to hi
            // if nums[mid]==target, we have to include in search space and go left
            if(nums[mid] >= target){
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        // cout<<nums[lo]<<" "<<nums[hi]<<"\n";
        if(nums[lo]==target){
            return lo;
        }
        if(nums[hi]==target){
            return hi;
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lowerBound(nums,target);
        int u = upperBound(nums,target);
        return {l,u};
    }
};