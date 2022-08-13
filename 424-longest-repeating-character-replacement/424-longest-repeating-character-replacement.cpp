class Solution {
public:
    int characterReplacement(string &s, int k) {
        int maxLen = -1;
        // dont take maxChar since mp[maxChar] could change if maxChars is s[l]
        // eg. s = AAAAABBBBC and k = 4, we can move l to index 2 and make it BBBBBBBBB
        // instead if A is taken as maxchar, l will move to index 6 and make it BBBBBB
        int maxCount = 0; // we can replace k elements. need not be same.
        vector<int> mp(256,0);
        
        int l=0;
        for(int r=0;r<s.length();r++){
            mp[s[r]]++;
            
            // if count of s[r] >= count of maxCount, update maxCount
            maxCount = max(maxCount, mp[s[r]]);
            
            // we don't need loop to update maxCount since maxcount in the window is always <= maxCount
            // when we move l to right, the maximum of counts remains less than the maxcount.
            while((r-l+1)-maxCount > k) {
                mp[s[l]]--;
                l++;
            }
            
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};