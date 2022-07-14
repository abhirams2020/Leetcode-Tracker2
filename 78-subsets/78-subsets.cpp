class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int> &nums, int i, vector<int> &op){
        if(i==nums.size()){
            ans.push_back(op);
            return;
        }
        op.push_back(nums[i]);
        solve(nums,i+1,op);
        op.pop_back();
        solve(nums,i+1,op);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> op;
        solve(nums,0,op);
        return ans;
    }
};