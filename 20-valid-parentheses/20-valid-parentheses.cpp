class Solution {
public:
    bool isValid(string str) {
        // if string length odd, cannot pair all
        if(str.length()%2){
            return false;
        }
        stack<char> st;
        unordered_set<char> open = {'(', '[', '{'};
        unordered_set<char> close = {')', ']', '}'};
        // mapping of opening to corresponding closing bracket
        unordered_map<char,char> mp = {{')','('}, {']','[' }, {'}','{'}};
        
        for(char ch:str) {
            if(open.count(ch)) {
                st.push(ch);
            }
            else if(close.count(ch)){
                // when ch is closing, we need stack.top(). if empty or not matching, return null
                if(st.empty() || st.top()!=mp[ch]){
                    return false;
                }
                st.pop();
            }
        }
        // if any unpaired opening bracket left, not valid
        if(!st.empty()){
            return false;
        }
        return true;
    }
};