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