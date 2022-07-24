class Solution {
public:
    int search(vector<int>& nums, int target) {
        // check if l to m or m to r is sorted.
        int n = nums.size();
        int l = 0, r = n-1;
        int count = 0;
        while(l<=r){
            int m = l + (r - l) / 2;
            // cout<<l<<" "<<r<<"\n";
            // if target found, return index of target
            if(nums[m]==target){
                return m;
            }
            // if search space is 1 element and target not found, return -1
            if(l==r){
                return -1;
            }
            // left part is sorted, check if target is there
            if(nums[l]<=nums[m]){
                if(target>=nums[l] && target<nums[m]){
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
            // right part is sorted, check if target in that range
            else if(nums[m] <= nums[r]){
                if(target>nums[m] && target<=nums[r]){
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            count++;
        }
        return -1;
    }
};