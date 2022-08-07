/*
class Solution {
public:
    long long mod = 1e9+7;
    
    unordered_map<char,unordered_set<char>> mp;
    
    vector<char> vowels = {'a','e','i','o','u'};
    
    int dp[20002][128];
    
    int solve(int n, int prev){
        if(n==0){
            return 1;
        }
        if(dp[n][prev]!=-1){
            return dp[n][prev];
        }
        int count = 0;
        for(auto ch:vowels){
            if(prev=='#' || mp[prev].count(ch)){
                count = (count + solve(n-1,ch))%mod;
            }
        }
        return dp[n][prev] = count;
    }
    
    int countVowelPermutation(int n) {
        mp['a'] = {'e'};
        mp['e'] = {'a','i'};
        mp['i'] = {'a','e','o','u'};
        mp['o'] = {'i','u'};
        mp['u'] = {'a'};
        memset(dp,-1,sizeof(dp));
        return solve(n,'#');
    }
};
*/

class Solution {
public:
    long long mod = 1e9+7;
    
    unordered_map<char,unordered_set<char>> mp;
    
    vector<char> vowels = {'a','e','i','o','u'};
    
    int dp[20002][27];
    
    int solve(int n, int prev){
        if(n==0){
            return 1;
        }
        if(dp[n][prev-'a']!=-1){
            return dp[n][prev-'a'];
        }
        int count = 0;
        for(auto ch:vowels){
            if(prev-'a'==26 || mp[prev].count(ch)){
                count = (count + solve(n-1,ch))%mod;
            }
        }
        return dp[n][prev-'a'] = count;
    }
    
    int countVowelPermutation(int n) {
        mp['a'] = {'e'};
        mp['e'] = {'a','i'};
        mp['i'] = {'a','e','o','u'};
        mp['o'] = {'i','u'};
        mp['u'] = {'a'};
        memset(dp,-1,sizeof(dp));
        char prev = 'a'+26;
        return solve(n, prev);
    }
};