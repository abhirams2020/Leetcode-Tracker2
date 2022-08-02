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
        string target1;
        string target2;
        // create the target strings with size = length of new s
        // for target1, at even index add 0, at odd index add 1
        for(int i=0;i<s.length();i++){
            if(i%2==0){
                target1 += '0';
                target2 += '1';
            }
            else {
                target1 += '1';
                target2 += '0';
            }
        }
        
        int left=0, right=0;
        int diff1=0, diff2=0, minDiff=INT_MAX;
        while(right<s.length()){
            // add right characters
            if(s[right]!=target1[right]){
                diff1++;
            }
            if(s[right]!=target2[right]){
                diff2++;
            }
            // if l to r window has size == k, update min value and move left ptr by 1
            if(right-left+1 == k){
                minDiff = min({minDiff, diff1, diff2});
                // move left of window
                if(s[left]!=target1[left]){
                    diff1--;
                }
                if(s[left]!=target2[left]){
                    diff2--;
                }
                left++;
            }
            right++;
        }
        
        return minDiff;
    }
};