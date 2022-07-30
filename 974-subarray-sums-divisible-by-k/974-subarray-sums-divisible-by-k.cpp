class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        // prefix sum array starting with 0 for showing 0 sum before adding elements
        vector<int> preSum(n+1,0);
        preSum[0] = 0;
        // find prefix sum
        for(int i=1;i<n+1;i++){
            preSum[i] = preSum[i-1] + nums[i-1];
        }
        // find remainder of prefix sums and check for no of subarrays with same remainder if rem!=0
        // if remainder == 0, it means prefix sum is divisible by k
        unordered_map<int,int> remCount;
        // increment count of starting 0 in presum
        remCount[0]++;
        int count = 0;
        for(int i=1;i<n+1;i++){
            int remainder = preSum[i]%k;
            // eg. remainder of -2 should be 3 instead of -2.
            if(remainder < 0){
                remainder += k;
            }
            if(remCount.count(remainder)){
                count += remCount[remainder];
            }
            remCount[remainder]++;
        }
        return count;
    }
};