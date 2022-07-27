class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        for(int i=0;i<strs[0].length();i++){
            char curr = strs[0][i];
            bool isMatch=true;
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]!=curr){
                    isMatch = false;
                }
            }
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