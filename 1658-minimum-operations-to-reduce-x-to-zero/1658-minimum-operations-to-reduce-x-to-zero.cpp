/*
// USING HASHMAP
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(auto &i:nums){
            sum += i;
        }
        int target = sum - x;
        // if sum of all elements = x, no of operation = removing all elements
        if(target==0){
            return nums.size();
        }
        // find largest subarray with sum = target
        map<int,int> mp; // mp[sum] = index where that sum found
        mp[0] = -1;
        int currSum = 0;
        int maxLen = -1;
        for(int i=0;i<nums.size();i++){
            currSum += nums[i];
            if(mp.count(currSum-target)){
                maxLen = max(maxLen, i - mp[currSum-target]);
            }
            if(mp.count(currSum)==0){
                mp[currSum] = i;
            }
        }
        // if no valid subarray found
        if(maxLen==-1){
            return -1;
        }
        return nums.size() - maxLen;
    }
};
*/

// USING SLIDING WINDOW
class Solution {
public:
    // since nums consist of +ve elements only, we can use sliding window
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(auto &i:nums){
            sum += i;
        }
        int target = sum - x;
        // if sum of all elements = x, no of operation = removing all elements
        if(target==0){
            return nums.size();
        }
        // find largest subarray with sum = target
        int currSum = 0;
        int maxLen = -1;
        int l = 0;
        for(int r=0;r<nums.size();r++){
            currSum += nums[r];
            
            while(l<r && currSum > target){
                currSum -= nums[l];
                l++;
            }
            
            if(currSum == target) {
                maxLen = max(maxLen, r-l+1);
            }
        }
        // if no valid subarray found
        if(maxLen==-1){
            return -1;
        }
        return nums.size() - maxLen;
    }
};