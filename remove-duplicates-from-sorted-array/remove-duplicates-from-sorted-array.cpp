class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, k=0;
        while(i<nums.size()){
            nums[k] = nums[i];
            int curr = nums[i];
            while(i<nums.size() && nums[i]==curr){
                i++;
            }
            k++;
        }
        return k;
    }
};