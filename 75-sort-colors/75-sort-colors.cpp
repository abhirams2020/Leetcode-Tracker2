class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 0 to l-1 will have all 0s
        // r+1 to n-1 will have all 2s
        int n = nums.size();
        int l=0, r=n-1;
        int i=0;
        while(i<=r){
            if(nums[i]==0){
                swap(nums[i],nums[l]);
                l++;
                i++;
            }
            else if(nums[i]==2){
                swap(nums[i],nums[r]);
                r--;
                // not doing i++ since number which was originally in r could be 0
                // so check that pos once again for 0 to swap nums[i] and nums[l]
            }
            else if(nums[i]==1) {
                i++;
            }
        }
    }
};