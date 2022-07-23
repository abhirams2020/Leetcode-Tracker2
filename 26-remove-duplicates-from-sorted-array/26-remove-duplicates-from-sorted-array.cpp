class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // use 2 pointer. add each unique element at l and move it
        // if duplicate elements are there, move i and keep l at same place
        // index l indicates that 0 to l has unique elements only.
        int l=0;
        for(int i=0;i<nums.size();i++){
            if(i==0 || nums[i]!=nums[i-1]){
                nums[l] = nums[i];
                l++;
            }
        }
        return l;
    }
};