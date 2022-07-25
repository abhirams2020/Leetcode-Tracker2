class Solution {
public:
    vector<string> ans;
    // open=no of open remaining to be added, close=no of close remaining
    void solve(int open, int close, string& str){
        if(close==0){
            ans.push_back(str);
            return;
        }
        // we can always add opening bracket
        if(open>0){
            str.push_back('(');
            solve(open-1,close,str);
            str.pop_back();
        }
        // for adding closing bracket, there should be a paired opening bracket
        // so no of opening remaining < no of closing remaining
        if(close>open){
            str.push_back(')');
            solve(open,close-1,str);
            str.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string str;
        solve(n,n,str);
        return ans;
    }
};