class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for(int k=2;k<=n;k++){
            string ans = "";
            for(int i=0;i<s.length();i++){
                int count = 1;
                while(i<s.length()-1 && s[i]==s[i+1]){
                    count++;
                    i++;
                }
                ans += to_string(count) + s[i];
            }
            s = ans;
        }
        return s;
    }
};