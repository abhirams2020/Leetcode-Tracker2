class Solution {
public:
    int mySqrt(int x) {
        long lo=1, hi=x;
        while(hi-lo>1){
            long long mid = lo+(hi-lo)/2;
            if(mid*mid <= x){
                lo = mid;
            }
            else {
                hi = mid-1;
            }
        }
        if(hi*hi <= x){
            return hi;
        }
        if(lo*lo <= x){
            return lo;
        }
        return -1;
    }
};