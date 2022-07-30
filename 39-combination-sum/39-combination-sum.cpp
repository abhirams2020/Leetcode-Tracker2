class Solution {
public:
    vector<vector<int>> res;
    
    void solve(vector<int> &candidates, int target, vector<int> &op, int i){
        if(target==0){
            res.push_back(op);
            return;
        }    
        if(i==candidates.size()){
            return;
        }
        if(candidates[i]<=target){
            op.push_back(candidates[i]);
            solve(candidates,target-candidates[i],op,i);
            op.pop_back();
            solve(candidates,target,op,i+1);
        }
        else {
            solve(candidates,target,op,i+1);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> op;
        solve(candidates, target, op, 0);
        return res;
    }
};