class Solution {
public:
    string solve(string &s){
        string ans;
        for(int i=0;i<s.length();i++){
            int count = 1;
            while(i<s.length()-1 && s[i]==s[i+1]){
                count++;
                i++;
            }
            ans = ans + to_string(count) + s[i];
        }
        return ans;
    }
    
    string countAndSay(int n) {
        string s = "1";
        for(int i=2;i<=n;i++){
            s = solve(s);
        }
        return s;
    }
};