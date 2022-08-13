class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> maxArr;
        int l = 0;
        for(int r=0;r<nums.size();r++){
            // keep the deque monotonic. ie for adding element at end, all elements lesser than it removed
            while(!dq.empty() && nums[r]>nums[dq[dq.size()-1]]){
                dq.pop_back();
            }
            dq.push_back(r);
            
            if(r-l+1 == k){
                // remove invalid index from dq by removing front elements less than l
                // after removing invalid, dq[0] will give max element in range l to r
                while(!dq.empty() && dq[0] < l){
                    dq.pop_front();
                }
                maxArr.push_back(nums[dq[0]]);
                l++;
            }
        }
        return maxArr;
    }
};