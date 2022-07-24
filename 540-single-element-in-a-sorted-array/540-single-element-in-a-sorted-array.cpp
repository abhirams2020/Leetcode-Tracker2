/*
// USING XOR FOR ALL ELEMENTS WILL GIVE SINGLE ELEMENT W/O PAIR
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l=0, r=n-1;
        int ans;
        
        // if only 1 single exist and rest are pairs, means array size is odd.
        // if when we find pair, we can search left and right of pair. choose portion with odd size
        while(l<=r){
            int m = l + (r-l)/2;
            // check left of mid for pair
            if(m>0 && nums[m-1]==nums[m]){
                // when pair found at (m-1,m) take 3 sections, l to m-2, m-1 to m, m+1 to r
                int leftSize = (m-2)-l+1;
                int rightSize = r-(m+1)+1;
                // if left of pair is odd, choose that
                if(leftSize%2!=0){
                    r = m-2;
                }
                else {
                    l = m+1;
                }
            }
            // check right of mid for pair
            else if(m<n-1 && nums[m]==nums[m+1]){
                // when pair found at (m-1,m) take 3 sections, l to m-1, m to m+1, m+2 to r
                int leftSize = (m-1)-l+1;
                int rightSize = r-(m+2)+1;
                // if left of pair is odd, choose that
                if(leftSize%2!=0){
                    r = m-1;
                }
                else {
                    l = m+2;
                }                
            }
            // if no pair found on left or right, means it is the single element
            else {
                ans = nums[m];
                break;
            }
        }
        return ans;
    }
};