class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_set<char> open = {'{', '[', '('};
        unordered_set<char> close = {'}', ']', ')'};
        unordered_map<char,char> bracketPair = {{'}', '{'}, {']', '['}, {')', '('}};
        for(auto ch:s){
            if(open.count(ch)){
                st.push(ch);
            }
            else if(close.count(ch)){
                if(!st.empty() && st.top() == bracketPair[ch]){
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};