class Solution {
public:
    int reverseNum(int num){
        int ans = 0;
        while(num > 0){
            int unitDigit = num%10;
            if(ans > INT_MAX/10 || (ans == INT_MAX/10 && unitDigit > INT_MAX%10)){
                return -1; // return an invalid number. since function finds reverse of positive num, -1 is invalid ans
            }
            ans = ans*10 + unitDigit;
            num = num/10;
        }
        return ans;
    }
    
    bool isPalindrome(int x) {
        // negative numbers is never palindrome
        if(x < 0){
            return false;
        }
        // if x = reverse of x, it is palindrome
        return x == reverseNum(x);
    }
};