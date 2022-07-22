// DP MEMOIZATION BY STORING COUNT OF LEFT AND RIGHT BRACKET SO FAR
class Solution {
public:
    bool flag = false;
    int dp[100][100][100];
    
    // all permutations of current expression by replacing * with brackets or empty
    bool isBalanced(string &s, int i, int left, int right){
        if(i==s.length()){
            if(left==right){
                return flag = true;
            }
            return false;
        }
        if(left < right){
            return false;
        }
        if(dp[i][left][right]!=-1){
            return dp[i][left][right];
        }
        bool ans = false;
        // if s[i] == '*', * can be replaced with (, ), or empty
        if(s[i]=='*'){
            ans = isBalanced(s,i+1,left,right) || isBalanced(s,i+1,left,right+1) || isBalanced(s,i+1,left+1,right);
        }
        // if s[i] is bracket, add to op
        else {
            if(s[i]==')'){
                ans = ans || isBalanced(s,i+1,left,right+1);
            }
            else if(s[i]=='('){
                ans = ans || isBalanced(s,i+1,left+1,right);
            }
        }
        return dp[i][left][right] = ans;
    }
        
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        bool ans = isBalanced(s,0,0,0);
        return flag;
    }
};