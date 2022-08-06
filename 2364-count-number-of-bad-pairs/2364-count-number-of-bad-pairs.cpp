class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long goodPairs = 0;
        unordered_map<int,long long> mp;
        for(int i=0;i<n;i++){
            if(mp.count(nums[i]-i)){
                goodPairs += mp[nums[i]-i];
            }
            mp[nums[i]-i]++;
        }
        long long totalPairs = (n-1)*(n)/2;
        return totalPairs - goodPairs;
    }
};