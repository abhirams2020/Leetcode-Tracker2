class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0, hi=nums.size()-1;
        while(hi-lo>1){
            int mid = lo + (hi - lo) / 2;
            if(target<nums[mid]){
                hi = mid - 1;
            }
            else {
                lo = mid;
            }
        }
        if(nums[lo]==target){
            return lo;
        }
        if(nums[hi]==target){
            return hi;
        }
        return -1;
    }
};