class Solution {
private:
    vector<vector<int>> res;
    
public:
    void solve(vector<int> &nums, vector<int> op, int i){
        if(i==nums.size()){
            res.push_back(op);
            return;
        }
        // get next non duplicate index
        int next_i;
        for(next_i=i+1;next_i<nums.size();next_i++){
            if(nums[next_i]!=nums[i]){
                break;
            }
        }
        // if we take an element, next element can be considered
        // if we dont take an element, skip to next non duplicate
        op.push_back(nums[i]);
        solve(nums,op,i+1);
        op.pop_back();
        solve(nums,op,next_i);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> op;
        sort(nums.begin(), nums.end());
        solve(nums, op, 0);
        return res;
    }
};