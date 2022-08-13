class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0;
        int maxLen = 0;
        unordered_map<char,int> mp;
        while(r<s.length()){
            // if s[r] already exist in current prev substring, move l till all occurrence of s[r] removed
            while(l<=r && mp.count(s[r]) > 0){
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
            mp[s[r]]++;
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};