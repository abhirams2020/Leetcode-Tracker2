/*
// sum from 0 to n is n*(n+1)/2. subtract sum of nums from this.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(auto i:nums){
            sum += i;
        }
        int n=nums.size();
        return (n*(n+1)/2) - sum;
    }
};
*/

// BY XOR ON RANGE [0,N] AND ELEMENTS IN LIST
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