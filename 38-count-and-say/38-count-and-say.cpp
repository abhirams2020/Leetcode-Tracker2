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
*/

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string x = countAndSay(n-1);
        string res = "";
        char temp = x[0];
        int count = 0;
        for(int i = 0; i < x.size(); i++) {
            if(temp == x[i])
                count++;
            else {
                res = res + to_string(count) + temp;
                temp = x[i];
                count = 1;
            }
        }
        res = res + to_string(count) + temp;
        return res;
    }
};