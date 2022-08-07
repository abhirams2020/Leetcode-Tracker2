// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo=1, hi=n;
        while(hi-lo>1){
            int mid = lo+(hi-lo)/2;
            if(isBadVersion(mid)==true){
                hi = mid;
            }
            else {
                lo = mid+1;
            }
        }
        // find first bad among lo and hi
        if(isBadVersion(lo)){
            return lo;
        }
        if(isBadVersion(hi)){
            return hi;
        }
        return -1;
    }
};