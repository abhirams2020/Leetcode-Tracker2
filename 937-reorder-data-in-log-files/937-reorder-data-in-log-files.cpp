class Solution {
public:
    bool isLetterLog(string &str){
        // find first character after a space
        int i=0;
        while(i<str.length() && str[i]!=' '){
            i++;
        }
        // check if content has letter or digits
        if('a'<=str[i+1] && str[i+1]<='z'){
            return true;
        }
        else {
            return false;
        }
    }
    
    static bool cmp(string &a, string &b){
        // find first index of whitespace character
        int i=0, j=0;
        while(i<a.length() && a[i]!=' '){
            i++;
        }
        while(j<b.length() && b[j]!=' '){
            j++;
        }
        // i and j currently at whitespace
        string id1 = a.substr(0,i), id2 = b.substr(0,j);
        string val1 = a.substr(i+1), val2 = b.substr(j+1);
        if(val1==val2){
            return id1 < id2;
        }
        return val1 < val2;
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res;
        vector<string> letters;
        vector<string> digits;
        for(auto str:logs){
            if(isLetterLog(str)){
                letters.push_back(str);
            }
            else {
                digits.push_back(str);
            }
        }
        sort(letters.begin(),letters.end(),cmp);
        // first sorted letters added. then digits added in relative order
        for(auto str:letters){
            res.push_back(str);
        }
        for(auto str:digits){
            res.push_back(str);
        }
        return res;
    }
};