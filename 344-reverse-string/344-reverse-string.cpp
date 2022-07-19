class Solution {
public:
    void reverse(vector<char>& s, int i){
        int n = s.size();
        if(i==n-1){
            return;
        }
        s.insert(s.begin()+i,s[n-1]);
        s.pop_back();
        reverse(s,i+1);
    }
        
    void reverseString(vector<char>& s) {
        reverse(s,0);
    }
};