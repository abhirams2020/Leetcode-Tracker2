// USING STRINGSTREAM
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss;
        ss<<s;
        vector<string> v;
        string str;
        while(ss>>str){
            v.push_back(str);
        }
        
        reverse(v.begin(),v.end());
        
        string ans;
        for(int i=0;i<v.size();i++){
            ans += v[i] + " ";
        }
        ans.pop_back();
        
        return ans;
    }
};