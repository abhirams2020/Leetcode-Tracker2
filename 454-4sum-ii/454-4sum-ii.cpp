class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int target = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        sort(nums3.begin(), nums3.end());
        sort(nums4.begin(), nums4.end());
        
        unordered_map<int,int> mp;
        
        for(auto i:nums1){
            for(auto j:nums2){
                mp[i+j]++;
            }
        }
        
        int count = 0;
        
        for(auto i:nums3){
            for(auto j:nums4){
                if(mp.count(target-(i+j))){
                    count += mp[target-(i+j)];
                }
            }
        }
        
        return count;
    }
};