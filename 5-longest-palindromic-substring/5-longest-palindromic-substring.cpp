class Solution {
public:
    pair<int,int> checkPal(string &s, int l, int r){
        while(l>=0 && r<s.length()){
            if(s[l]!=s[r]){
                break;
            }
            l--;
            r++;
        }
        return {l+1,r-1};
    }
    
    string longestPalindrome(string &s) {
        int maxLen = 0;
        string maxPal;
        // consider single index as center of palindrome and check
        for(int i=0;i<s.length();i++){
            auto it = checkPal(s,i,i);
            int l = it.first, r = it.second;
            int currLen = r-l+1;
            if(currLen > maxLen){
                maxLen = currLen;
                maxPal = s.substr(l, currLen);
            }
        }
        // consider two consecutive index  as center of palindrome and check
        for(int i=0;i<s.length()-1;i++){
            auto it = checkPal(s,i,i+1);
            int l = it.first, r = it.second;
            int currLen = r-l+1;
            if(currLen > maxLen){
                maxLen = currLen;
                maxPal = s.substr(l, currLen);
            }
        }
        return maxPal;
    }
};