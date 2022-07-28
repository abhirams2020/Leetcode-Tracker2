/*
// ITERATIVE METHOD
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        // since we already got value for 1, start from 2 till n
        for(int k=2;k<=n;k++){
            string ans = "";
            // function to count numbers as a sequence
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
*/

// USING RECURSION FN(N) = COUNT(FN(N-1))
class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string s = countAndSay(n-1);
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
};