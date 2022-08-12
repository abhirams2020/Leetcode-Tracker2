class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i=0;i<32;i++){
            // first move the current value to left and make space for new value at right end
            // then make right end value = n&1 and reduce n to n>>1
            ans = ans << 1;
            ans = ans | (n&1);
            n = n >> 1;
        }
        return ans;
    }
};