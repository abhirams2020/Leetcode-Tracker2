class Solution {
public:
    string convert(string s, int numRows) {
        // if numrows == 1, no need of zigzag traversal. so just the given string
        if(numRows == 1){
            return s;
        }
        // we create a array of strings where every row is a string
        // till end of row, row direction is down. when end of row is reached, change row direction to up.
        // no need of column direction since it is always in same direction. so only row index is enough.
        vector<string> strArr(numRows);
        
        int currR = 0;
        
        int dir = 1;
        
        int i = 0;
        
        while(i<s.length()){
            strArr[currR].push_back(s[i]);
            if(currR == numRows-1){
                dir = -1;
            }
            else if(currR == 0){
                dir = 1;
            }
            currR = currR + dir;
            i++;
        }
        
        string ans;
        
        // read all rows of strArr and add the strings to ans
        for(auto &str:strArr){
            ans += str;
        }
        
        return ans;
    }
};