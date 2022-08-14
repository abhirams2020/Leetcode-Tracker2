class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        bool isNegative = false;
        // skip the whitespaces
        for(;i<s.length();i++){
            // if sign or number encountered, break from loop
            if(s[i] != ' '){
                break;
            }
        }
        
        // if curr index at -, the result should be negative
        if(s[i]=='-'){
            isNegative = true;
            i++;
        }
        else if(s[i]=='+'){
            isNegative = false;
            i++;
        }
        
        // input the number characters to num string
        string num;
        while(i<s.length() && (s[i] >= '0' && s[i] <= '9')) {
            num.push_back(s[i]);
            i++;
        }
        
        // convert the number string to integer
        int ans = 0;
        for(auto &c:num){
            // check if adding new digit will cause overflow
            if(ans>INT_MAX/10 || (ans==INT_MAX/10 && (c-'0')>INT_MAX%10)){
                if(isNegative){
                    return INT_MIN;
                }
                return INT_MAX;
            }
            ans = ans*10 + (int)(c-'0');
        }
        
        if(isNegative){
            return -ans;
        }
        return ans;
    }
};