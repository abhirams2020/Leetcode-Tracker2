class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pos=0;
        int j = 0; // pointer for val index
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return j;
    }
};