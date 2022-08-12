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