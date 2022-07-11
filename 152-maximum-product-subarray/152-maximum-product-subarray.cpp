class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMin=nums[0], currMax=nums[0], maxProd=nums[0];
        for(int i=1;i<nums.size();i++){
            int prevMin = currMin, prevMax = currMax;
            currMin = min(nums[i], min(nums[i]*prevMin, nums[i]*prevMax));
            currMax = max(nums[i], max(nums[i]*prevMin, nums[i]*prevMax));
            maxProd = max(maxProd, currMax);
        }
        return maxProd;
    }
};