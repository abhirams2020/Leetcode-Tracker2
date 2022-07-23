class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0;
        int maxCount = 0;
        // while(i<nums.size()){
        //     if(nums[i]==1){
        //         int count = 0;
        //         while(i<nums.size() && nums[i]==1){
        //             count++;
        //             i++;
        //         }
        //         maxCount = max(maxCount, count);
        //     }
        //     else {
        //         i++;
        //     }
        // }
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count = 0;
            }
            else if(nums[i]==1){
                count++;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};