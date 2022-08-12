/*
class Solution {
public:
    int count1Bit(uint32_t n) {
        int count = 0;
        while(n>0){
            count += n&1;
            n = n>>1;
        }
        return count;
    }
    
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            int currCount = count1Bit(i);
            ans.push_back(currCount);
        }
        return ans;
    }
};
*/

// USING DP TO STORE COUNT BITS OF NUMBERS
class Solution {
public:
    int dp[100000];
    
    int count1Bit(int n) {
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n] = (n&1) + count1Bit(n>>1);
    }
    
    vector<int> countBits(int n) {
        memset(dp,-1,sizeof(dp));
        vector<int> ans;
        for(int i=0;i<=n;i++){
            int currCount = count1Bit(i);
            ans.push_back(currCount);
        }
        return ans;
    }
};