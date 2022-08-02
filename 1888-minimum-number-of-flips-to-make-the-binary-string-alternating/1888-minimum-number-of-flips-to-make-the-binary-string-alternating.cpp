class Solution {
public:
    int minFlips(string s) {
        // k is required window size
        int k = s.length();
        // append s to itself for sliding window.
        // when we move window it is similar to remove from front and append to back
        s += s;
        // for each window we compare with the string of same size with alternate numbers
        // alternates can start with 0 or 1. count flips required to convert to each and take min
        string alt1;
        string alt2;
        // create the alternate strings with size = length of new s
        int currVal = 0;
        for(int i=0;i<s.length();i++){
            alt1 += to_string(currVal);
            alt2 += to_string(1 - currVal);
            currVal = (currVal+1)%2;
        }
        
        int left=0, right=0;
        int count1=0, count2=0, minCount=INT_MAX;
        while(right<s.length()){
            // add right characters
            if(s[right]!=alt1[right]){
                count1++;
            }
            if(s[right]!=alt2[right]){
                count2++;
            }
            // if l to r window has size == k, update min value and move left ptr by 1
            if(right-left+1 == k){
                minCount = min({minCount, count1, count2});

                if(s[left]!=alt1[left]){
                    count1--;
                }
                if(s[left]!=alt2[left]){
                    count2--;
                }
                left++;
            }
            right++;
        }
        
        return minCount;
    }
};