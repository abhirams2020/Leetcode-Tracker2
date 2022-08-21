class Solution {
public:
    string largestPalindromic(string num) {
        // find sum of all even occurrence and largest odd occurence
        // if only zero found in even or odd, dont include
        unordered_map<char,int> mp;
        for(auto &c:num){
            mp[c]++;
        }
        char midChar = '0'-1;
        
        string evenStr;
        
        for(auto &[k,v]:mp){
            if(v%2==0){
                for(int i=0;i<v/2;i++){
                    evenStr += k;
                }
            }
            else {
                midChar = max(midChar, k);
                for(int i=0;i<(v-1)/2;i++){
                    evenStr += k;
                }
            }
        }
        
        sort(evenStr.begin(), evenStr.end(), greater<>());
        
        // check if leading zeros only
        bool flag0 = true;
        for(auto &c:evenStr){
            if(c!='0'){
                flag0 = false;
                break;
            }
        }
        string ans;
        // if even is not 0 only, add evenStr + midChar + reverse(evenStr);
        if(flag0 == false){
            ans += evenStr;
            if(midChar != '0'-1)
                ans += midChar;
            reverse(evenStr.begin(), evenStr.end());
            ans += evenStr;
        }
        else {
            if(midChar != '0'-1)
                ans += midChar;
        }
        flag0 = true;
        for(auto &c:ans){
            if(c!='0'){
                flag0 = false;
                break;
            }
        }
        if(flag0==true){
            return "0";
        }
        return ans;
    }
};