class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int l = 0, r = nums.size()-1; // index of possible largest squared numbers
        int i = nums.size()-1;
        while(l<=r){
            int lval = nums[l]*nums[l], rval = nums[r]*nums[r];
            if(rval > lval){
                ans[i] = rval;
                r--;
            }
            else{
                ans[i] = lval;
                l++;
            }
            i--;
        }
        return ans;
    }
};