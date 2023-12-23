class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currCnt=0, maxCnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=1){
                currCnt = 0;
            }
            else {
                currCnt++;
            }
            maxCnt = max(maxCnt, currCnt);
        }
        return maxCnt;
    }
};