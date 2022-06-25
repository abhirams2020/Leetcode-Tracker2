class Solution {
public:
    // check if the majority element we got is actually majority
    bool isMajority(vector<int> &nums, int maj){
        int count = 0;
        for(auto i:nums){
            if(i==maj){
                count++;
            }
        }
        return count > nums.size()/2;
    }
    
    // function to find majority element
    int majorityElement(vector<int>& nums) {
        int maj, count = 0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                maj = nums[i];
            }
            if(maj == nums[i]){
                count++;
            }
            else {
                count--;
            }
        }
        // this step is important. but since in question given majority will exist, not reqd
        if(!isMajority(nums,maj)){
            return -1;
        }
        return maj;
    }
};