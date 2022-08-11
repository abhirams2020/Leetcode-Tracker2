class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {      
        string ans;
        bool isMatch=true;
        for(int i=0;i<strs[0].length();i++){
            char curr = strs[0][i]; // take every character from first word and compare 
            // compare current character with i'th index for words 1 to n-1
            for(int j=1;j<strs.size();j++){
                // if word[j] does not have i'th index or i'th index character different, ismatch = false
                if(i==strs[j].length() || strs[j][i]!=curr){
                    isMatch = false;
                }
            }
            // if ismatch is false, break from the loop
            if(isMatch==true){
                ans.push_back(curr);
            }
            else {
                break;
            }
        }
        return ans;
    }
};