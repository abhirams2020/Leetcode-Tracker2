class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        // we XOR 0 to n with all elements of nums
        // eg nums is [3,0,1], ans = 0^1^2^3 ^ 3^0^1 = 2 which is missing num
        for(auto &i:nums){
            ans ^= i;
        }
        for(int i=0;i<=nums.size();i++){
            ans ^= i;
        }
        return ans;
    }
};