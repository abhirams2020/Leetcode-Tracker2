class Solution {
public:
    bool isLetterLog(string &log){
        stringstream ss(log);
        string word;
        ss>>word;
        while(ss>>word){
            if('0'<=word[0] && word[0]<='9'){
                return false;
            }
        }
        return true;    
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
        vector<string> letterLogs;
        vector<string> digitLogs;
        vector<string> ans;
        for(auto &log:logs){
            if(isLetterLog(log)){
                letterLogs.push_back(log);
            }
            else {
                digitLogs.push_back(log);
            }
        }
        // first sorted letters added. then digits added in relative order
        sort(letterLogs.begin(), letterLogs.end(), cmp);
        for(auto &log:letterLogs){
            ans.push_back(log);
        }
        for(auto &log:digitLogs){
            ans.push_back(log);
        }
        return ans;
    }
};