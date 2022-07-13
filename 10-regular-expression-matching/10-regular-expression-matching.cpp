class Solution {
public:
    int dp[31][21];
    
    // solve(s,t,i,j) checks if s[i] to s[m-1] match t[j] to t[n-1]
    bool solve(string &str, string &target, int i, int j) {
        // reached end of both, means str is matching target
        if(i==str.length() && j==target.length()){
            return true;
        }
        // reached end of str but still target not matched
        if(i==str.length()){
            return false;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        // Case-1 : if str[i] has * next to it, str[i] can be taken 0 times till n times
        //          in this case, at i, we can skip to i+2 or remain at i and check if str[i] match target[j]
        // Case-2 : if str pointer at alphabet, check if equal and move both to next
        // Case-3 : if str pointer is at '.', move both to next
        
        bool ans = false;
        
        // check if current i and j are a valid match.
        bool match = i<str.length() && j<target.length() && (str[i]==target[j] || str[i]=='.');
        
        if(i+1<str.length() && str[i+1]=='*') {
            if(match)
                ans = solve(str,target,i,j+1) || solve(str,target,i+2,j);
            else
                ans = solve(str,target,i+2,j);
        }
        else if(match){
            ans = solve(str,target,i+1,j+1);
        }
        return dp[i][j] = ans;
    }
    
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return solve(p,s,0,0);    
    }
};