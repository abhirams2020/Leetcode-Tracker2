/*
// BY SEGREGATING POSITIVE AND NEGATIVE NUMBERS AND CHECKING ONLY POSITIVE PART OF ARRAY
class Solution {
public:
    // segregate the array to negative and positive parts and return starting index of positive nos.
    int sortNegPos(vector<int> &nums){
        int pIndex=0; // left of pIndex should be all negative
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0){
                swap(nums[pIndex],nums[i]);
                // change negative number to positive for marking positive as visited while checking
                nums[pIndex] = 1;
                pIndex++;
            }
        }
        return pIndex;
    }
    
    int firstMissingPositive(vector<int>& nums) {
        int pIndex = sortNegPos(nums);
        // if no positive elements in nums, return 1
        if(pIndex==nums.size()){
            return 1;
        }
        int len = nums.size();
        // in array of size len, first missing positive can be in range 1 to len.
        // visit all elements in positive range. if the number in range [1,len], change arr[arr[i]-1] to negative
        for(int i=pIndex;i<nums.size();i++){
            if(nums[i]<=len){
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
        return len+1;
    }
};
*/

// BY MAKING ALL INVALID VALUES TO LEN+1 AND MARK VALID NUMBER INDEX TO NEGATIVE
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        // valid missing positive will be in range 1 to len. if not found, return next positive ie len+1
        // change all invalid values -> negative and more than len to len+1
        // here we change negative to positive since while marking index as visited, we make it negative
        for(int i=0;i<len;i++){
            if(nums[i]<=0 || nums[i]>len){
                nums[i] = len+1;
            }
        }
        // when valid nums[i] found, mark is corresponding index as visited by making it negative
        for(int i=0;i<len;i++){
            int curr = abs(nums[i]);
            if(curr>=1 && curr<=len){
                // curr index is corresponding index of nums[i]. ie 0 for nums[i]=1
                nums[curr-1] = -abs(nums[curr-1]);
            }
        }
        // find first number in 1 to len range which has not been visited
        for(int i=0;i<len;i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return len+1;
    }
};