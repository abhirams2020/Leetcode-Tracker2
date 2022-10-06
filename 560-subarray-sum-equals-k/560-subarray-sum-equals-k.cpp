class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, currSum = 0;
        for(auto i:nums){
            currSum += i;
            if(mp.find(currSum - k) != mp.end()){
                count+=mp[currSum-k];
            }
            mp[currSum]++;
        }
        return count;
    }
};