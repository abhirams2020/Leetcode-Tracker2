class Solution {
public:
    vector<vector<string>> res;
    
    bool isPalindrome(string &s, int left, int right){
        while(left < right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
    void solve(string &s, vector<string> &op, int index){
        if(index==s.length()){
            res.push_back(op);
            return;
        }
        for(int i=index;i<s.length();i++){
            if(isPalindrome(s,index,i)){
                op.push_back(s.substr(index, i-index+1));
                solve(s, op, i+1);
                op.pop_back();                
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string> op;
        solve(s,op,0);
        return res;
    }
};