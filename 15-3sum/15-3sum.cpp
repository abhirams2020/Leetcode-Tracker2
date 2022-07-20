class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int req = 0;
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }
            int currSum = req - nums[i];
            unordered_set<int> s;
            int l=i+1, r=nums.size()-1;
            while(l<r){
                if(l!=i+1 && nums[l] == nums[l-1]){
                    l++;
                    continue;
                }
                if(r!=nums.size()-1 && nums[r] == nums[r+1]){
                    r--;
                    continue;
                }
                if(nums[l] + nums[r] == currSum){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
                else if(nums[l] + nums[r] < currSum){
                    l++;
                }
                else if(nums[l] + nums[r] > currSum){
                    r--;
                }
            }
        }
        return ans;
    }
};