class Solution {
public:
    using pii = pair<int,int>;
    
    int dp[601][101][101];
    
    pii count01(string &s){
        int one=0, zero=0;
        for(auto c:s){
            if(c=='0'){
                zero++;
            }
            else {
                one++;
            }
        }
        return {zero,one};
    }
    
    int knapsack(vector<string> &strs, int index, int m, int n){
        // if end of strs is reached, return 0. we need not get exactly m 0s and n 1s
        // objective is to get max size subset of strs with AT MOST m 0s and n 1s.
        if(index==strs.size()){
            return 0;
        }
        if(dp[index][m][n]!=-1){
            return dp[index][m][n];
        }
        
        // count no of 0 and 1 in curr string
        auto it = count01(strs[index]);
        int i = it.first, j = it.second;
        
        int include=0, notInclude=0;
        
        // if curr string has less than no of zeros and ones reqd, include it
        if(i<=m && j<=n){
            include = 1 + knapsack(strs, index+1, m-i, n-j);
        }
        notInclude = knapsack(strs, index+1, m, n);
        
        return dp[index][m][n] = max(include, notInclude);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return knapsack(strs,0,m,n);
    }
};