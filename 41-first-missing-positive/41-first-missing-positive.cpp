class Solution {
public:
    // sort non positive to left and positive to right in array
    int sortNegPos(vector<int> &nums){
        // left of pIndex should be all negative
        int pIndex=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0){
                swap(nums[pIndex],nums[i]);
                nums[pIndex] = 1;
                pIndex++;
            }
        }
        return pIndex;
    }
    
    int firstMissingPositive(vector<int>& nums) {
        // segregate the array to negative and positive parts and return starting index of positive nos.
        int pIndex = sortNegPos(nums);
        // if no positive elements in nums, return 1
        if(pIndex==nums.size()){
            return 1;
        }
        int len = nums.size();
        // in array of size len, first missing positive can be in range 1 to len.
        // visited all elements in positive range. if the number in range [1,len], change arr[arr[i]-1] to negative
        for(int i=pIndex;i<nums.size();i++){
            if(nums[i]<=len){
                // when a +ve number found, mark its index as negative
                int currIndex = abs(nums[i])-1;
                nums[currIndex] = -abs(nums[currIndex]);
            }
        }
        // in array check if any number in range 0 to len-1 has not been marked visited, ie still positive
        int i;
        for(i=0;i<len;i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return i+1;
    }
};