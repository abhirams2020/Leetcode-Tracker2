/*
// DP MEMOIZATION BY STORING COUNT OF LEFT AND RIGHT BRACKET SO FAR
// FOR VALID PARENTHESIS, LEFT SHOULD ALWAYS BE MORE THAN OR EQUAL TO RIGHT
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

// DP WITH MEMOIZATION BY COUNTING NUMBER OF UNMATCHED LEFT SO FAR
// IF UNMATCHED LEFT < 1, RETURN FALSE
class Solution {
public:
    int dp[101][101];
    
    // all permutations of current expression by replacing * with brackets or empty
    bool isBalanced(string &s, int i, int left){
        if(i==s.length()){
            if(left==0){
                return true;
            }
            return false;
        }
        if(left < 0){
            return false;
        }
        if(dp[i][left]!=-1){
            return dp[i][left];
        }
        bool ans = false;
        // if s[i] == '*', * can be replaced with (, ), or empty
        if(s[i]=='*'){
            ans = isBalanced(s,i+1,left) || isBalanced(s,i+1,left-1) || isBalanced(s,i+1,left+1);
        }
        // if s[i] is bracket, add to op
        else {
            if(s[i]==')'){
                ans = ans || isBalanced(s,i+1,left-1);
            }
            else if(s[i]=='('){
                ans = ans || isBalanced(s,i+1,left+1);
            }
        }
        return dp[i][left] = ans;
    }
        
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return isBalanced(s,0,0);
    }
};
*/

class Solution {
public:
    bool checkValidString(string s) {
        // leftMin = min no of unmatched left possible
        // leftMax = max no of unmatched left possible
        int leftMax=0, leftMin=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                leftMin++;
                leftMax++;
            }
            else if(s[i]==')'){
                leftMin--;
                leftMax--;
            }
            else if(s[i]=='*'){
                leftMin = leftMin-1;
                leftMax = leftMax+1;
            }
            if(leftMin<0){
                leftMin=0;
            }
            if(leftMax<0){
                return false;
            }
        }
        return leftMin==0;
    }
};