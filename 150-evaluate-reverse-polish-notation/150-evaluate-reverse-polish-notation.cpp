class Solution {
public:
    int solve(int first, int second, string oper){
        int res;
        if(oper=="+"){
            res = first + second;
        }
        else if(oper=="-"){
            res = first - second;
        }
        else if(oper=="*"){
            res = first * second;
        }
        else if(oper=="/"){
            res = first / second;
        }
        return res;
    }
    
    int evalRPN(vector<string>& tokens) {
        // push to str if number. if sign get 2 top elements from str, operate and push it
        stack<int> st;
        unordered_set<string> oper = {"+", "-", "/", "*"};
        for(auto str:tokens){
            if(oper.count(str)){
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                
                int val = solve(first,second,str);
                st.push(val);
            }
            else {
                // convert string to int before pushing in stack
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};