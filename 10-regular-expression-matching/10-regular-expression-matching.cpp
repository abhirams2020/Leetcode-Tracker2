class Solution {
public:
    int dp[31][21];
    
    bool solve(string &str, string &target, int i, int j) {
        // cout<<i<<" "<<j<<"\n";
        if(i==str.length() && j==target.length()){
            return true;
        }
        // reached end of str but still target not found
        if(i==str.length()){
            return false;
        }
        // if target reached end but str is not reached end
        if(j==target.length()){
            // if there is no * at str[i+1], return false
            // if str[i+1] is *, means we can skip str[i] and move to i+2.
            if(i+1<str.length() && str[i+1]=='*'){
                return dp[i][j] = solve(str,target,i+2,j);
            }
            return false;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        // Case-1 : if str[i] has * next to it, str[i] can be taken 0 times till n times
        //          in this case, at i, we can skip to i+2 or remain at i and check if str[i] match target[j]
        // Case-2 : if both pointer at alphabet, check if equal and move both to next
        // Case-3 : if str pointer is at '.', move both to next
        
        bool ans = false;
        
        if(i+1<str.length() && str[i+1]=='*') {
            if(str[i]==target[j] || str[i]=='.')
                ans = solve(str,target,i,j+1) || solve(str,target,i+2,j);
            else 
                ans = solve(str,target,i+2,j);
        }
        else if(isalpha(str[i])){
            if(str[i]==target[j])
                ans = solve(str,target,i+1,j+1);
        }
        else if(str[i]=='.'){
            ans = solve(str,target,i+1,j+1);
        }
        return dp[i][j] = ans;
    }
    
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return solve(p,s,0,0);    
    }
};