class Solution {
public:
    vector<vector<int>> res;
    
    void solve(vector<int> &nums, int i, vector<int> &op){
        if(i==nums.size()){
            res.push_back(op);
            return;
        }
        op.push_back(nums[i]);
        solve(nums,i+1,op);
        op.pop_back();
        solve(nums,i+1,op);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> op;
        solve(nums, 0, op);
        return res;
    }
};