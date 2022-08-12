class Solution {
public:
    unordered_map<uint32_t,int> dp;
    
    int count1Bit(uint32_t n) {
        if(n==0){
            return 0;
        }
        if(dp.count(n)){
            return dp[n];
        }
        return dp[n] = (n&1) + count1Bit(n>>1);
    }
    
    int hammingWeight(uint32_t n) {
        return count1Bit(n);
    }
};