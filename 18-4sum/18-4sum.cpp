class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // set<vector<int>> res;
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;){
            long long target1 = (long long)target - nums[i];
            for(int j=i+1;j<n;){
                int left = j+1, right = n-1;
                long long target2 = target1-nums[j]; // nums[l] + nums[r] = target - (nums[i] + nums[j])

                while(left < right){
                    long long sum = nums[left]+nums[right]; 
                    if(sum < target2){
                        left++;
                    }
                    else if(sum > target2){
                        right--;
                    }
                    else {
                        res.push_back({nums[i],nums[j],nums[left],nums[right]});
                        int curr_left = left, curr_right = right;
                        while(left<right && nums[left]==nums[curr_left]){
                            left++;
                        }
                        while(left<right && nums[right]==nums[curr_right]){
                            right--;
                        }
                    }
                }
                int curr_j = j;
                // Processing the duplicates of number 2
                while(j<n && nums[j] == nums[curr_j]){
                    j++;
                }
            }
            int curr_i = i;
            // Processing the duplicates of number 1
            while(i<n && nums[i] == nums[curr_i]){
                i++;
            }
        }
        return res;
    }
};