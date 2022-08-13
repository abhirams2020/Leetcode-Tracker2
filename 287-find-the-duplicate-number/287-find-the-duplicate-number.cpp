/*
class Solution {
public:
    // there are n+1 numbers in range [1,n].
    // when a number is found. make nums[abs(number)] to negative
    // negative at index i indicates i was found before
    
    int findDuplicate(vector<int>& nums) {
        int ans;
        
        // find duplicate
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])] < 0){
                ans = abs(nums[i]);
                break;
            }
            nums[abs(nums[i])] = -(nums[abs(nums[i])]);
        }
        
        // restore nums to original value
        for(int i=0;i<nums.size();i++){
            nums[i] = abs(nums[i]);
        }
        return ans;
    }
};
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // similar to finding start of cycle in linked list
        int fast = 0, slow = 0;
        // start from nums[0] and move fast with 2x speed of slow
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(fast==slow){
                break;
            }
        }
        // when cycle found, move one pointer to beginning and move both at same speed
        // the point where they meet is start of cycle
        slow = 0;
        while(fast != slow){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};