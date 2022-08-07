/*
// MEMOIZATION DP. O(5*N) TIME. O(26*N) SPACE.
class Solution {
public:
    long long mod = 1e9+7;
    
    unordered_map<char,unordered_set<char>> mp;
    
    int dp[20002][26];
    
    int solve(int n, int prev){
        if(n==0){
            return 1;
        }
        if(dp[n][prev-'a']!=-1){
            return dp[n][prev-'a'];
        }
        int count = 0;
        for(auto ch:mp[prev]){
            count = (count + solve(n-1,ch))%mod;
        }
        return dp[n][prev-'a'] = count;
    }
    
    int countVowelPermutation(int n) {
        mp['n'] = {'a','e','i','o','u'}; // n is for condition when no element included so far
        mp['a'] = {'e'};
        mp['e'] = {'a','i'};
        mp['i'] = {'a','e','o','u'};
        mp['o'] = {'i','u'};
        mp['u'] = {'a'};
        memset(dp,-1,sizeof(dp));
        return solve(n, 'n');
    }
};
*/

// ITERATIVE METHOD. O(N) TIME. O(1) SPACE.
class Solution {
public:
    
    int countVowelPermutation(int n) {
        long long mod = 1e9+7;
        
        vector<long long> dp(128,1);
        
        for(int i=1;i<n;i++){
            long long   prev_a = dp['a'], 
                        prev_e = dp['e'], 
                        prev_i = dp['i'], 
                        prev_o = dp['o'], 
                        prev_u = dp['u'];
            // find new count from previous counts
            dp['a'] = prev_e % mod;
            dp['e'] = (prev_a + prev_i) % mod;
            dp['i'] = (prev_a + prev_e + prev_o + prev_u) % mod;
            dp['o'] = (prev_i + prev_u) % mod;
            dp['u'] = prev_a % mod;
        }
        return (dp['a'] + dp['e'] + dp['i'] + dp['o'] + dp['u']) % mod;
    }
};