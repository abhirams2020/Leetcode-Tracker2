class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        // for every index i, no of occurrance of arr[i] = (i+1) * (n-i)
        // eg for [1,4,2,5,3], subarray with 1 is [1],[1,4],[1,4,2],[1,4,2,5],[1,4,2,5,3]
        // no of occurrence of 1 is (0+1) * (5-0) =  1 * 5 = 5
        // no of odd occurrence of 1 = 3, no of even occurrence = 5
        // from observation, out of total no of occurrence, ceil(total/2) is odd, floor(total/2) is even
        // find odd occurrence for all index from 0 to n-1 and add to get total sum
        int n = arr.size();
        int oddSum = 0;
        for(int i=0;i<n;i++){
            double currTotal = (i+1) * (n-i);
            int oddTotal = ceil(currTotal/2);
            oddSum += (oddTotal * arr[i]); // currSum = value * no of counts in odd subarrays
        }
        
        return oddSum;
    }
};