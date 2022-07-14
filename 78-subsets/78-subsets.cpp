class Solution {
public:
    vector<vector<int>> ans;
    
    void solve2(vector<int> &nums, int i, vector<int> &op){
        if(i==nums.size()){
            ans.push_back(op);
            return;
        }
        op.push_back(nums[i]);
        solve(nums,i+1,op);
        op.pop_back();
        solve(nums,i+1,op);
    }
    
    void solve(vector<int> &nums, int idx, vector<int> &op){
        ans.push_back(op);
        for(int i=idx;i<nums.size();i++){
            op.push_back(nums[i]);
            solve(nums,i+1,op);
            op.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> op;
        solve(nums,0,op);
        return ans;
    }
};