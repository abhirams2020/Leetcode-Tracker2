class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        // taking remainder and adding to ans*10 works for both +ve and -ve integers
        // for negative, the remainder and ans is negative always. so it adds like positive.
        while(x!=0){
            int unitDigit = x%10;
            // if ans already more than INT_MAX/10 or ans=INT_MAX/10 and new unitdigit more than INT_MAX%10
            if(ans > INT_MAX/10 || (ans==INT_MAX/10 && unitDigit >= INT_MAX%10)){
                return 0;
            }
            if(ans < INT_MIN/10 || (ans==INT_MAX/10 && unitDigit <= INT_MIN%10)){
                return 0;
            }            
            ans = ans*10 + unitDigit;
            x = x/10;
        }
        return ans;
    }
};