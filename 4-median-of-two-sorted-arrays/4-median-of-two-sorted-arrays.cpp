class Solution {
public:
    int INF = 1e6+1;
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1>n2){
            return findMedianSortedArrays(nums2, nums1);
        }
        int medSize = (n1+n2)/2;
        
        int lo=0, hi=n1;
        while(lo<=hi){
            int mid1 = (lo+hi)/2;
            int mid2 = medSize - mid1;
            int left1 = -INF, right1 = INF, left2 = -INF, right2 = INF;
            if(mid1 > 0) left1 = nums1[mid1-1];
            if(mid1 < n1) right1 = nums1[mid1];
            if(mid2 > 0) left2 = nums2[mid2-1];
            if(mid2 < n2) right2 = nums2[mid2];
            
            if(left1 <= right2 && left2 <= right1){
                // we found median cutting, now return value depending on size of combined array
                // cout<<left1<<" "<<right1<<" , "<<left2<<" "<<right2<<"\n";
                if((n1+n2)%2==0){
                    return (min((double)right1, (double)right2) + max((double)left1, (double)left2))/2.0;
                }
                else {
                    return min((double)right1, (double)right2);
                }
            }
            else if(left1 > right2){
                hi = mid1-1;
            }
            else if(left2 > right1){
                lo = mid1+1;
            }
        }
        return -1;
    }
};