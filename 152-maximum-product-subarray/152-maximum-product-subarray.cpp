class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMin=nums[0], currMax=nums[0], maxProd=nums[0];
        for(int i=1;i<nums.size();i++){
            // store the currmin and currmax values since we can get a maximum value from nums[i]*currmax or nums[i]*currmin.
            // eg. if nums[i] is negative and currmin is negative, it can give largest product so currmin should also be stored.
            // IMP : since we're modifying currmin and currmax values, store the currmin and currmax values before modifying.
            int prevMin = currMin, prevMax = currMax;
            currMin = min(nums[i], min(nums[i]*prevMin, nums[i]*prevMax));
            currMax = max(nums[i], max(nums[i]*prevMin, nums[i]*prevMax));
            maxProd = max(maxProd, currMax);
        }
        return maxProd;
    }
};