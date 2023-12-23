class Solution {
public:
    // moving val to end of array. like 3 color flag problem
    // i only moves till j is met. slightly better than below soln.
    int removeElement(vector<int>& nums, int val) {
        int i=0, j=nums.size()-1;
        // left of i contains all non val elements.
        // right of j contains all val elements.
        // while swapping we only move 1 ptr since not sure about swapped value in other ptr
        while(i<=j){
            if(nums[i]==val){
                swap(nums[i],nums[j]);
                j--;
            }
            else {
                i++;
            }
        }
        return i;
    }
    
    // both i and j start from 0. i travels through whole array
    int removeElement1(vector<int>& nums, int val) {
        int j = 0; // pointer for val index
        // 0 to j-1 will always have non val. so after swap, arr[j] cant be val
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return j;
    }
};