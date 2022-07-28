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
        else {
            string x = countAndSay(n-1);                    // recursion
            string res = "";                                // result will be appended in this
            char temp = x[0];                               // storing first character of the string
            int count = 0;
            for(int i = 0; i < x.size(); i++) {
                if(temp == x[i])                            // checking the number of times the will appear continuously
                    count++;
                else {
                    res += to_string(count) + temp;         // when another number arrives, append the previous number
                    temp = x[i];                            // update temp
                    count = 1;                              // count the occurence of the new number
                }
            }
            res += to_string(count) + temp;                 // to append the last number
            return res;
         }
    }
};