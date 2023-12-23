class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m-1, p2 = n-1, end = m+n-1;
        // compare p1 and p2 and add max to end of nums1
        while(p1>=0 && p2>=0){
            if(nums1[p1] > nums2[p2]){
                nums1[end] = nums1[p1];
                p1--;
            }
            else {
                nums1[end] = nums2[p2];
                p2--;
            }
            end--;
        }
        // if p1 has any element left, add to end
        while(p1>=0){
            nums1[end] = nums1[p1];
            p1--;
            end--;
        }
        // if p2 has any element left, add to end
        while(p2>=0){
            nums1[end] = nums2[p2];
            p2--;
            end--;
        }
        return;
    }
};