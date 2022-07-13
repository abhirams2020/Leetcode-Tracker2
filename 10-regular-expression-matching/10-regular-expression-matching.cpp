class Solution {
public:
    int dp[31][21];
    
    bool solve(string &str, string &target, int i, int j) {
        // cout<<i<<" "<<j<<"\n";
        if(i==str.length() && j==target.length()){
            return true;
        }
        if(i==str.length()){
            return false;
        }
        if(j==target.length()){
            if(i+1<str.length() && str[i+1]=='*'){
                return solve(str,target,i+2,j);
            }
            return false;
        }
        // cout<<i<<" "<<j<<" "<<str[i]<<" "<<target[j]<<" "<<prev<<"\n";
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        // if both pointer at alphabet, check if equal and move both to next
        // if str pointer is at '*', we can move the j pointer or move i pointer if prev matches str[i]
        // if str pointer is at '.', move both to next
        
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
        // cout<<s.length()<<" "<<p.length()<<"\n";
        memset(dp,-1,sizeof(dp));
        return solve(p,s,0,0);    
    }
};