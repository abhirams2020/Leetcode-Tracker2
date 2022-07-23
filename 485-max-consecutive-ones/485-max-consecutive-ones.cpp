class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0;
        int maxCount = 0;
        while(i<nums.size()){
            if(nums[i]==1){
                int count = 0;
                while(i<nums.size() && nums[i]==1){
                    count++;
                    i++;
                }
                maxCount = max(maxCount, count);
            }
            else {
                i++;
            }
        }
        return maxCount;
    }
};